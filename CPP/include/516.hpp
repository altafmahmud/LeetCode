// 516. Longest Palindromic Subsequence
// Medium
// Given a string s, find the longest palindromic subsequence's length in s.

// A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

// Example 1:

// Input: s = "bbbab"
// Output: 4
// Explanation: One possible longest palindromic subsequence is "bbbb".

// Example 2:

// Input: s = "cbbd"
// Output: 2
// Explanation: One possible longest palindromic subsequence is "bb".

// Constraints:

// 1 <= s.length <= 1000
// s consists only of lowercase English letters.

#pragma once

#include <string>
#include <vector>
#include <algorithm>

// Iterative dynamic programming solution
// Space complexity O(n^2)
class LongestPalindromicSubsequence
{
public:
    int longestPalindromeSubseq(std::string s)
    {
        const auto length = s.size();
        std::vector<std::vector<int>> dp(length, std::vector<int>(length));
        for (int i = s.size() - 1; i >= 0; --i)
        {
            dp[i][i] = 1;
            for (int j = i + 1; j < s.size(); ++j)
            {
                if (s[i] == s[j])
                {
                    dp[i][j] = 2 + dp[i + 1][j - 1];
                }
                else
                {
                    dp[i][j] = std::max(dp[i][j - 1], dp[i + 1][j]);
                }
            }
        }
        return dp[0][length - 1];
    }
};

// Iterative dynamic programming solution
// Space complexity O(n)
class LongestPalindromicSubsequenceImproved
{
public:
    int longestPalindromeSubseq(std::string s)
    {
        const auto length = s.size();
        std::vector<int> dp(length);
        std::vector<int> dp_prev(length);
        for (int i = s.size() - 1; i >= 0; --i)
        {
            dp[i] = 1;
            for (int j = i + 1; j < s.size(); ++j)
            {
                if (s[i] == s[j])
                {
                    dp[j] = 2 + dp_prev[j - 1];
                }
                else
                {
                    dp[j] = std::max(dp[j - 1], dp_prev[j]);
                }
            }
            dp_prev = dp;
        }
        return dp[length - 1];
    }
};
