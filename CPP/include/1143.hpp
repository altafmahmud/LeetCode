// 1143. Longest Common Subsequence
// Medium
// Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

// A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing
// the relative order of the remaining characters.

// For example, "ace" is a subsequence of "abcde".
// A common subsequence of two strings is a subsequence that is common to both strings.

// Example 1:

// Input: text1 = "abcde", text2 = "ace"
// Output: 3
// Explanation: The longest common subsequence is "ace" and its length is 3.

// Example 2:

// Input: text1 = "abc", text2 = "abc"
// Output: 3
// Explanation: The longest common subsequence is "abc" and its length is 3.

// Example 3:

// Input: text1 = "abc", text2 = "def"
// Output: 0
// Explanation: There is no such common subsequence, so the result is 0.

// Constraints:

// 1 <= text1.length, text2.length <= 1000
// text1 and text2 consist of only lowercase English characters.

#pragma once

#include <string>
#include <vector>

class LongestCommonSubsequence
{
public:
    int longestCommonSubsequence(std::string text1, std::string text2)
    {
        const auto len1 = text1.length();
        unsigned longest = 0;
        std::vector<unsigned> len_vec(len1);
        for (const auto c2 : text2)
        {
            unsigned curr_len = 0;
            for (auto i = 0; i < len1; ++i)
            {
                auto &val = len_vec[i];
                if (val > curr_len)
                {
                    curr_len = val;
                }
                else if (c2 == text1[i])
                {
                    val = curr_len + 1;
                    if (curr_len > longest)
                    {
                        longest = curr_len;
                    }
                }
            }
        }
        return longest;
    }
};

class LongestCommonSubsequenceNew
{
public:
    int longestCommonSubsequence(std::string text1, std::string text2)
    {
        std::vector<int> dp(text1.length(), 0);
        int longest = 0;

        for (char c : text2)
        {
            int curLength = 0;
            for (int i = 0; i < dp.size(); i++)
            {
                auto &val = dp[i];
                if (curLength < val)
                {
                    curLength = val;
                }
                else if (c == text1[i])
                {
                    val = curLength + 1;
                    longest = std::max(longest, curLength + 1);
                }
            }
        }
        return longest;
    }
};