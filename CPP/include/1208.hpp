// 1208. Get Equal Substrings Within Budget
// Medium
// You are given two strings s and t of the same length and an integer maxCost.
// You want to change s to t. Changing the ith character of s to ith character of t costs |s[i] - t[i]| (i.e., the absolute difference between the ASCII values of the characters).
// Return the maximum length of a substring of s that can be changed to be the same as the corresponding substring of t with a cost less than or equal to maxCost.
// If there is no substring from s that can be changed to its corresponding substring from t, return 0.

// Example 1:
// Input: s = "abcd", t = "bcdf", maxCost = 3
// Output: 3
// Explanation: "abc" of s can change to "bcd".
// That costs 3, so the maximum length is 3.

// Example 2:
// Input: s = "abcd", t = "cdef", maxCost = 3
// Output: 1
// Explanation: Each character in s costs 2 to change to character in t,  so the maximum length is 1.

// Example 3:
// Input: s = "abcd", t = "acde", maxCost = 0
// Output: 1
// Explanation: You cannot make any change, so the maximum length is 1.

// Constraints:
// 1 <= s.length <= 10^5
// t.length == s.length
// 0 <= maxCost <= 10^6
// s and t consist of only lowercase English letters.

#pragma once

#include <vector>
#include <string>
#include <numeric>

class EqualSubstrInBudget
{
public:
    int equalSubstring(std::string s, std::string t, int maxCost)
    {
        auto binOp = [](const auto val1, const auto val2) -> unsigned
        {
            return std::abs(val1 - val2);
        };
        std::vector<unsigned> diff;
        diff.reserve(s.length());
        std::transform(t.begin(), t.end(), s.begin(), std::back_inserter(diff), binOp);
        const auto sum = std::accumulate(diff.begin(), diff.end(), 0);
        if (sum <= maxCost)
        {
            return s.length();
        }
        auto maxLen = 0;
        auto idx1 = 0;
        auto idx2 = 0;
        auto len = 0;
        while (idx1 < diff.size() - 1)
        {
            if (s.length() - idx1 <= maxLen)
            {
                break;
            }
            auto cost = diff[idx1];
            len = 0;
            idx2 = idx1 + 1;
            while (idx2 < diff.size() && cost <= maxCost)
            {
                if (cost + diff[idx2] <= maxCost)
                {
                    cost += diff[idx2];
                }
                else
                {
                    len = idx2 - idx1;
                    maxLen = (len > maxLen) ? len : maxLen;
                    break;
                }
                ++idx2;
            }
            if (idx2 >= diff.size())
            {
                len = idx2 - idx1;
                maxLen = (len > maxLen) ? len : maxLen;
                break;
            }
            ++idx1;
        }
        return maxLen;
    }
};
