// 29. Divide Two Integers
// Medium
// Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.

// The integer division should truncate toward zero, which means losing its fractional part. For example, 8.345 would be truncated to 8, and -2.7335 would be truncated to -2.

// Return the quotient after dividing dividend by divisor.

// Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−2^31, 2^31 − 1].
// For this problem, if the quotient is strictly greater than 2^31 - 1, then return 2^31 - 1, and if the quotient is strictly less than -2^31, then return -2^31.

// Example 1:

// Input: dividend = 10, divisor = 3
// Output: 3
// Explanation: 10/3 = 3.33333.. which is truncated to 3.

// Example 2:

// Input: dividend = 7, divisor = -3
// Output: -2
// Explanation: 7/-3 = -2.33333.. which is truncated to -2.

// Constraints:

// > -2^31 <= dividend, divisor <= 2^31 - 1
// > divisor != 0

#pragma once

#include <limits>
#include <numeric>

class DivideTwoInt
{
public:
    int divide(int dividend, int divisor)
    {
        if (dividend == 0)
        {
            return 0;
        }
        const auto min_32 = std::numeric_limits<int32_t>::min();
        const auto max_32 = std::numeric_limits<int32_t>::max();
        auto negative = (dividend < 0) ^ (divisor < 0);
        int32_t quotient = 0;
        unsigned abs_dividend = (dividend < 0) ? std::labs(dividend) : dividend;
        unsigned abs_divisor = (divisor < 0) ? std::labs(divisor) : divisor;
        if (abs_dividend < abs_divisor)
        {
            return 0;
        }
        if (abs_divisor == 1)
        {
            if (negative)
            {
                return (dividend < 0) ? dividend : -dividend;
            }
            else if (dividend < 0)
            {
                if (dividend == min_32)
                {
                    return max_32;
                }
                return static_cast<int32_t>(abs_dividend);
            }
        }
        if (abs_dividend == abs_divisor)
        {
            return (negative) ? -1 : 1;
        }
        while (abs_dividend >= abs_divisor)
        {
            unsigned temp_abs_divisor = abs_divisor;
            unsigned multiple = 1;
            while (abs_dividend >= (temp_abs_divisor << 1))
            {
                temp_abs_divisor <<= 1;
                multiple <<= 1;
                if (abs_dividend == temp_abs_divisor)
                {
                    break;
                }
            }
            abs_dividend -= temp_abs_divisor;
            quotient += multiple;
        }
        return (negative) ? -quotient : quotient;
    }
};
