
// 214. Shortest Palindrome
// Hard
// You are given a string s. You can convert s to a
// palindrome by adding characters in front of it.

// Return the shortest palindrome you can find by performing this transformation.

// Example 1:

// Input: s = "aacecaaa"
// Output: "aaacecaaa"

// Example 2:

// Input: s = "abcd"
// Output: "dcbabcd"

// Constraints:

// 0 <= s.length <= 5 * 10^4
// s consists of lowercase English letters only.

#pragma once

#include <string>

class ShortestPalindrome
{
public:
    std::string shortestPalindrome(std::string s)
    {
        if (s.empty())
        {
            return s;
        }
        auto startSuffix = prefixPalindrome(s);
        if (startSuffix == s.size())
        {
            return s;
        }
        auto nonPalindromeSuffix = s.substr(startSuffix);
        auto revSuffix = nonPalindromeSuffix;
        std::reverse(revSuffix.begin(), revSuffix.end());
        return revSuffix + shortestPalindrome(s.substr(0, startSuffix)) + nonPalindromeSuffix;
    }

private:
    int prefixPalindrome(const std::string &s)
    {
        int left = 0;
        for (int right = s.size() - 1; right >= 0; --right)
        {
            if (s[left] == s[right])
            {
                ++left;
            }
        }
        return left;
    }
};
