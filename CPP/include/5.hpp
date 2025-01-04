// 5. Longest Palindromic Substring
// Medium
// Given a string s, return the longest palindromic substring in s.

// Example 1:

// Input: s = "babad"
// Output: "bab"
// Explanation: "aba" is also a valid answer.
// Example 2:

// Input: s = "cbbd"
// Output: "bb"

// Constraints:

// 1 <= s.length <= 1000
// s consist of only digits and English letters.

#pragma once

#include <string>
#include <utility>

class LongestPalindromicSubstr
{
public:
    std::string longestPalindrome(std::string &s)
    {
        std::string longest_palindrome;
        for (auto i = 0; i < s.size(); ++i)
        {
            auto idx_pair = expand(s, i, i);
            if (idx_pair.second - idx_pair.first + 1 > longest_palindrome.size())
            {
                longest_palindrome = s.substr(idx_pair.first, idx_pair.second - idx_pair.first + 1);
            }
            if (i < s.size() - 1 && s[i] == s[i + 1])
            {
                idx_pair = expand(s, i, i + 1);
                if (idx_pair.second - idx_pair.first + 1 > longest_palindrome.size())
                {
                    longest_palindrome = s.substr(idx_pair.first, idx_pair.second - idx_pair.first + 1);
                }
            }
        }
        return longest_palindrome;
    }

private:
    std::pair<int, int> expand(const std::string &s, const int left, const int right)
    {
        auto i = left;
        auto j = right;
        while (i >= 0 && j < s.size() && s[i] == s[j])
        {
            --i;
            ++j;
        }
        return std::make_pair(i + 1, j - 1);
    }
};