// 14. Longest Common Prefix
// Easy

// Write a function to find the longest common prefix string amongst an array of strings.

// If there is no common prefix, return an empty string "".

// Example 1:

// Input: strs = ["flower","flow","flight"]
// Output: "fl"

// Example 2:

// Input: strs = ["dog","racecar","car"]
// Output: ""
// Explanation: There is no common prefix among the input strings.

// Constraints:

// 1 <= strs.length <= 200
// 0 <= strs[i].length <= 200
// strs[i] consists of only lowercase English letters.

#pragma once

#include <string>
#include <vector>

class LongestCommonPrefix
{
public:
    std::string longestCommonPrefix(const std::vector<std::string> &strs)
    {
        std::string lcp("");
        char c = '\0';
        auto cond = true;
        for (unsigned col = 0; cond && col <= 200; ++col)
        {
            for (unsigned row = 0; row < strs.size(); ++row)
            {
                if (strs[row].size() == col)
                {
                    cond = false;
                    break;
                }
                char ch = strs[row][col];
                c = (c == '\0') ? ch : c;
                if (c != ch)
                {
                    cond = false;
                    break;
                }
            }
            if (cond && (c != '\0'))
            {
                lcp += c;
                c = '\0';
            }
        }
        return lcp;
    }
};