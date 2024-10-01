
#include "pch.h"
#include "CppUnitTest.h"
#include "../5.3/5.3.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unittest53
{
    TEST_CLASS(unittest53)
    {
    public:

        // |x| >= 1
        TEST_METHOD(TestT_AbsXGreaterOrEqualTo1)
        {
            double x = 1.5;
            double result = t(x);

            double expected = (cos(x) + 1) / (exp(x) + sin(x) * sin(x));

            Assert::AreEqual(expected, result, 0.000001, L"Test failed for |x| >= 1");
        }

        // |x| < 1
        TEST_METHOD(TestT_AbsXLessThan1)
        {
            double x = 0.1;
            double result = t(x);

            double expected = x - (x * x * x) / 6;

            Assert::AreEqual(expected, result, 0.000001, L"Test failed for |x| < 1");
        }

        // x = 0
        TEST_METHOD(TestT_Zero)
        {
            double x = 0.0;
            double result = t(x);

            double expected = 0.0;
            Assert::AreEqual(expected, result, 0.000001, L"Test failed for x = 0");
        }
    };
}

