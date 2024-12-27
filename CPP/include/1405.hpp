// 1405. Longest Happy String
// Medium

// A string s is called happy if it satisfies the following conditions:

// s only contains the letters 'a', 'b', and 'c'.
// s does not contain any of "aaa", "bbb", or "ccc" as a substring.
// s contains at most a occurrences of the letter 'a'.
// s contains at most b occurrences of the letter 'b'.
// s contains at most c occurrences of the letter 'c'.
// Given three integers a, b, and c, return the longest possible happy string. If there are multiple longest happy strings, return any of them.
// If there is no such string, return the empty string "".

// A substring is a contiguous sequence of characters within a string.

// Example 1:

// Input: a = 1, b = 1, c = 7
// Output: "ccaccbcc"
// Explanation: "ccbccacc" would also be a correct answer.

// Example 2:
// Input: a = 7, b = 1, c = 0
// Output: "aabaa"
// Explanation: It is the only correct answer in this case.

// Constraints:

// 0 <= a, b, c <= 100
// a + b + c > 0

#pragma once

#include <string>
#include <map>

class LongestHappyString
{
public:
    std::string longestDiverseString(int a, int b, int c)
    {
        std::string happyStr;
        if (a > 0)
        {
            freqCharHash.emplace(std::make_pair(a, 'a'));
        }
        if (b > 0)
        {
            freqCharHash.emplace(std::make_pair(b, 'b'));
        }
        if (c > 0)
        {
            freqCharHash.emplace(std::make_pair(c, 'c'));
        }

        auto lastChar = '\0';
        auto charToAppend = '\0';
        while (!freqCharHash.empty())
        {
            auto appendOne = false;
            auto itr = freqCharHash.begin();
            auto key = itr->first;
            if (freqCharHash.count(key) == 1)
            {
                if (itr->second == lastChar)
                {
                    ++itr;
                    if (itr == freqCharHash.end())
                    {
                        break;
                    }
                    key = itr->first;
                    appendOne = true;
                }
                charToAppend = itr->second;
            }
            else
            {
                auto range = freqCharHash.equal_range(key);
                for (auto range_itr = range.first; range_itr != range.second; ++range_itr)
                {
                    if (range_itr->second != lastChar)
                    {
                        charToAppend = range_itr->second;
                        break;
                    }
                }
            }
            const auto original_key = key;
            happyStr += charToAppend;
            --key;
            if (!appendOne && key >= 1)
            {
                happyStr += charToAppend;
                --key;
            }
            lastChar = charToAppend;
            eraseChar(original_key, charToAppend);
            if (key > 0)
            {
                insertElement(key, charToAppend);
            }
        }

        return happyStr;
    }

private:
    void eraseChar(const int key, const char c)
    {
        auto range = freqCharHash.equal_range(key);
        for (auto itr = range.first; itr != range.second; ++itr)
        {
            if (itr->second == c)
            {
                freqCharHash.erase(itr);
                break;
            }
        }
    }

    bool insertElement(const int key, const char c)
    {
        return (freqCharHash.emplace(std::make_pair(key, c)) != freqCharHash.end());
    }

    std::multimap<int, char, std::greater<int>> freqCharHash;
};