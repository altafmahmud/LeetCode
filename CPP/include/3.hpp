// 3. Longest Substring Without Repeating Characters

// Medium

// Given a string s, find the length of the longest substring without repeating characters.

// Example 1:

// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.

// Example 2:

// Input: s = "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.

// Example 3:

// Input: s = "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3.
// Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

// Constraints:

// 0 <= s.length <= 5 * 10^4
// s consists of English letters, digits, symbols and spaces.

#pragma once

#include <iostream>
#include <string>
#include <unordered_map>

class LongestSubstrWithoutRepChar
{
public:
    unsigned lengthOfLongestSubstring(const std::string &s)
    {
        std::unordered_map<char, int> charMap;
        unsigned ls_len = 0;
        unsigned ls_len_max = 0;
        int jdx = 0;
        int idx = 0;
        while (idx < s.length())
        {
            const char c = s[idx];
            auto find_itr = charMap.find(c);
            if (find_itr != charMap.end())
            {
                if (ls_len > ls_len_max)
                {
                    ls_len_max = ls_len;
                }
                ls_len = 0;
                const auto fdx = find_itr->second;
                while (jdx < fdx)
                {
                    charMap.erase(s[jdx++]);
                }
                ++jdx;
                find_itr->second = idx;
            }
            else
            {
                charMap.emplace(std::make_pair(c, idx));
                ls_len = idx - jdx + 1;
            }
            ++idx;
        }
        if (ls_len > ls_len_max)
        {
            ls_len_max = ls_len;
        }
        return ls_len_max;
    }
};