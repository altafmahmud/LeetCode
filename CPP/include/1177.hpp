// 1177. Can Make Palindrome from Substring

// You are given a string s and array queries where queries[i] = [lefti, righti, ki]. We may rearrange the substring s[lefti...righti] for each query and then choose up to ki of them
// to replace with any lowercase English letter.

// If the substring is possible to be a palindrome string after the operations above, the result of the query is true. Otherwise, the result is false.

// Return a boolean array answer where answer[i] is the result of the ith query queries[i].

// Note that each letter is counted individually for replacement, so if, for example s[lefti...righti] = "aaa", and ki = 2, we can only replace two of the letters.
// Also, note that no query modifies the initial string s.

// Example :

// Input: s = "abcda", queries = [[3,3,0],[1,2,0],[0,3,1],[0,3,2],[0,4,1]]
// Output: [true,false,false,true,true]
// Explanation:
// queries[0]: substring = "d", is palidrome.
// queries[1]: substring = "bc", is not palidrome.
// queries[2]: substring = "abcd", is not palidrome after replacing only 1 character.
// queries[3]: substring = "abcd", could be changed to "abba" which is palidrome. Also this can be changed to "baab" first rearrange it "bacd" then replace "cd" with "ab".
// queries[4]: substring = "abcda", could be changed to "abcba" which is palidrome.

// Example 2:

// Input: s = "lyb", queries = [[0,1,0],[2,2,1]]
// Output: [false,true]

// Constraints:

// > 1 <= s.length, queries.length <= 10^5
// > 0 <= lefti <= righti < s.length
// > 0 <= ki <= s.length
// > s consists of lowercase English letters.

// This solution is done by following other corresponding solutions due to Time Limit Exceeded problem

#pragma once

#include <vector>
#include <array>
#include <string>

class CanMakePaliFrmSubstr
{
public:
    std::vector<bool> canMakePaliQueries(const std::string &s, const std::vector<std::vector<int>> &queries)
    {
        std::vector<bool> res;
        std::array<int, 26> count_arr{};
        std::vector<std::array<int, 26>> prefix_count;
        prefix_count.reserve(s.size() + 1);
        prefix_count.push_back(count_arr);
        for (auto idx = 0; idx < s.size(); ++idx)
        {
            const auto &ch = s[idx];
            ++count_arr[ch - 'a'];
            prefix_count.push_back(count_arr);
        }
        for (const auto &query : queries)
        {
            if ((query[1] - query[0]) == 0)
            {
                res.push_back(true);
                continue;
            }
            if ((query[1] - query[0]) == 1)
            {
                if (s[query[1]] == s[query[0]])
                {
                    res.push_back(true);
                }
                else if (query[2] >= 1)
                {
                    res.push_back(true);
                }
                else
                {
                    res.push_back(false);
                }
                continue;
            }
            auto sum = 0, num_odd = 0;
            const auto &last_count_arr = prefix_count[query[1] + 1];
            const auto &first_count_arr = prefix_count[query[0]];
            for (auto idx = 0; idx < last_count_arr.size(); ++idx)
            {
                const auto ch_count = last_count_arr[idx] - first_count_arr[idx];
                sum += ch_count;
                if (ch_count % 2 != 0)
                {
                    ++num_odd;
                }
            }
            num_odd -= (sum % 2 == 0) ? 0 : 1;
            res.push_back(num_odd <= 2 * query[2]);
        }
        return res;
    }
};