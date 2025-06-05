#include "pch.h"
#include "CppUnitTest.h"
#include "input.h"
#include <sstream>
#include <iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace OPItest
{
    TEST_CLASS(InputTests)
    {
    public:
        // ���� ��� �������� ����� ����������� ���������� ��������� � ��������
        TEST_METHOD(CorrectInputTest)
        {
            unsigned int NumTroinik;
            int* Troinik;

            std::istringstream input_stream("3\n5\n2\n7\n");
            std::streambuf* orig = std::cin.rdbuf(input_stream.rdbuf());

            getInput(NumTroinik, Troinik);
            std::cin.rdbuf(orig);

            Assert::AreEqual(static_cast<unsigned int>(3), NumTroinik);
            Assert::IsNotNull(Troinik);
            Assert::AreEqual(5, Troinik[0]);
            Assert::AreEqual(2, Troinik[1]);
            Assert::AreEqual(7, Troinik[2]);

            delete[] Troinik;
        }

        // �������� �� double ���������� ���������
        TEST_METHOD(DoubleInputTest)
        {
            std::istringstream input_stream("3.5\n");
            std::streambuf* old_cin = std::cin.rdbuf();
            std::cin.rdbuf(input_stream.rdbuf());

            Assert::ExpectException<std::invalid_argument>([] {
                unsigned int NumTroinik;
                int* Troinik;

                getInput(NumTroinik, Troinik);
                });

            std::cin.rdbuf(old_cin);
        }

        // ���� ��� �������� �� ������������� ���������� ���������
        TEST_METHOD(NegativeInputTest)
        {
            unsigned int NumTroinik;
            int* Troinik;

            std::istringstream input_stream("-3\n");
            std::streambuf* orig = std::cin.rdbuf(input_stream.rdbuf());

            try
            {
                getInput(NumTroinik, Troinik);

                Assert::Fail(L"���������� �� ���� �������.");
            }
            catch (const std::invalid_argument& e)
            {
                Assert::IsTrue(std::string(e.what()).find("�������� ���������� ���������.") != std::string::npos);
            }

            std::cin.rdbuf(orig);
        }

        TEST_METHOD(MinimumInputTest)
        {
            unsigned int NumTroinik;
            int* Troinik;

            std::istringstream input_stream("1\n5\n");
            std::streambuf* orig = std::cin.rdbuf(input_stream.rdbuf());

            getInput(NumTroinik, Troinik);

            Assert::AreEqual(static_cast<unsigned int>(1), NumTroinik);
            Assert::IsNotNull(Troinik);
            Assert::AreEqual(5, Troinik[0]);

            delete[] Troinik;

            std::cin.rdbuf(orig);
        }

        // ���� ��� �������� ����� ������������� ���������� ���������
        TEST_METHOD(TestGetInputWithThousandTroinik)
        {
            unsigned int NumTroinik;
            int* Troinik = nullptr;
            std::stringstream input;

            input << "1000\n";

            for (int i = 0; i < 1000; ++i) {
                input << "10\n";
            }

            std::cin.rdbuf(input.rdbuf());

            try {
                getInput(NumTroinik, Troinik);

                Assert::AreEqual(1000u, NumTroinik, L"���������� ��������� ������ ���� 1000.");

                for (unsigned int i = 0; i < NumTroinik; i++) {
                    Assert::AreEqual(10, Troinik[i], L"���������� �������� � ������ �������� ������ ���� 10.");
                }

                delete[] Troinik;

            }
            catch (const std::invalid_argument& e) {
                Assert::Fail(L"���������� �� ������ ���� ���� �������.");
            }
        }


        // ���� �� 0 �������� �������� � ��������
        TEST_METHOD(TestGetInputWithZeroSockets)
        {
            unsigned int NumTroinik;
            int* Troinik = nullptr;

            std::stringstream input;

            input << "1\n";
            input << "0\n";

            std::cin.rdbuf(input.rdbuf());

            try {
                getInput(NumTroinik, Troinik);
                Assert::Fail(L"��������� ���������� ��� ����� 0 ��������.");
            }
            catch (const std::invalid_argument& e) {

                Assert::AreEqual("�������� ���������� ��������.", e.what(), L"��������� ���������� ������ ���� '�������� ���������� ��������'.");
            }

            if (Troinik != nullptr) {
                delete[] Troinik;
            }
        }

        // ���� �1 ��� �������� �� ���������� ��������
        TEST_METHOD(MinimumTroinikInputTest)
        {
            unsigned int NumTroinik;
            int* Troinik;

            std::istringstream input_stream("1\n1\n");
            std::streambuf* orig = std::cin.rdbuf(input_stream.rdbuf());

            getInput(NumTroinik, Troinik);

            Assert::AreEqual(static_cast<unsigned int>(1), NumTroinik);
            Assert::IsNotNull(Troinik);
            Assert::AreEqual(1, Troinik[0]);

            delete[] Troinik;

            std::cin.rdbuf(orig);
        }

        // ���� �2 ��� �������� �� ���������� ��������
        TEST_METHOD(MaximumTroinikInputTest)
        {
            unsigned int NumTroinik;
            int* Troinik;

            std::istringstream input_stream("1\n1000\n");
            std::streambuf* orig = std::cin.rdbuf(input_stream.rdbuf());

            getInput(NumTroinik, Troinik);

            Assert::AreEqual(static_cast<unsigned int>(1), NumTroinik);
            Assert::IsNotNull(Troinik);
            Assert::AreEqual(1000, Troinik[0]);

            delete[] Troinik;

            std::cin.rdbuf(orig);
        }

        // ���� ��� �������� ��������� ���������� �������� � ��������

        TEST_METHOD(TestGetInputWithTooManySockets)
        {
            unsigned int NumTroinik;
            int* Troinik = nullptr;

            std::stringstream input;

            input << "1\n";
            input << "100001\n";

            std::cin.rdbuf(input.rdbuf());

            try {
                getInput(NumTroinik, Troinik);
                Assert::Fail(L"��������� ���������� ��� ����� 1001 �������.");
            }
            catch (const std::invalid_argument& e) {

                Assert::AreEqual("�������� ���������� ��������.", e.what(), L"��������� ���������� ������ ���� '�������� ���������� ��������'.");
            }

            if (Troinik != nullptr) {
                delete[] Troinik;
            }
        }

        // ���� ��� �������� �������� �������������� ��������
        TEST_METHOD(VeryNegativeTroinikInputTest)
        {
            unsigned int NumTroinik;
            int* Troinik;

            std::istringstream input_stream("1\n-1000000\n");
            std::streambuf* orig = std::cin.rdbuf(input_stream.rdbuf());

            try
            {
                getInput(NumTroinik, Troinik);

                Assert::Fail(L"���������� �� ���� �������/");
            }
            catch (const std::invalid_argument& e)
            {
                Assert::IsTrue(std::string(e.what()).find("�������� ���������� ��������/") != std::string::npos);
            }

            std::cin.rdbuf(orig);
        }
    };
}