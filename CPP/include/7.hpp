// 7. Reverse Integer
// Medium
// Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

// Assume the environment does not allow you to store 64-bit integers (signed or unsigned). 

// Example 1:

// Input: x = 123
// Output: 321

// Example 2:

// Input: x = -123
// Output: -321

// Example 3:

// Input: x = 120
// Output: 21
 
// Constraints:
// -2^31 <= x <= 2^31 - 1

#include <limits>

constexpr int max_limit = std::numeric_limits<int>::max() / 10;
constexpr int min_limit = std::numeric_limits<int>::min() / 10;

class ReverseInteger {
public:
    int reverse(int x) {
        int rev = 0;
        int pop = 0;
        do {
            pop = x % 10;
            x /= 10;
            if (rev > max_limit || rev == max_limit && pop > 7) {
                return 0;
            } else if (rev < min_limit || rev == min_limit && pop < -8) {
                return 0;
            }
            rev = rev * 10 + pop;
        } while (x != 0);
        return rev;
    }
};