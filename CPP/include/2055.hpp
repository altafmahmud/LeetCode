// 2055. Plates Between Candles

// There is a long table with a line of plates and candles arranged on top of it. You are given a 0-indexed string s consisting of characters '*' and '|' only,
// where a '*' represents a plate and a '|' represents a candle.

// You are also given a 0-indexed 2D integer array queries where queries[i] = [lefti, righti] denotes the substring s[lefti...righti] (inclusive).
// For each query, you need to find the number of plates between candles that are in the substring. A plate is considered between candles if there is at least one candle
// to its left and at least one candle to its right in the substring.

// For example, s = "||**||**|*", and a query [3, 8] denotes the substring "*||**|". The number of plates between candles in this substring is 2, as each of the
// two plates has at least one candle in the substring to its left and right.

// Return an integer array answer where answer[i] is the answer to the ith query.

// Example 1:

// Input: s = "**|**|***|", queries = [[2,5],[5,9]]
// Output: [2,3]
// Explanation:
// - queries[0] has two plates between candles.
// - queries[1] has three plates between candles.
// Example 2:

// Input: s = "***|**|*****|**||**|*", queries = [[1,17],[4,5],[14,17],[5,11],[15,16]]
// Output: [9,0,0,0,0]
// Explanation:
// - queries[0] has nine plates between candles.
// - The other queries have zero plates between candles.

// Constraints:

// > 3 <= s.length <= 10^5
// > s consists of '*' and '|' characters.
// > 1 <= queries.length <= 10^5
// > queries[i].length == 2
// > 0 <= lefti <= righti < s.length

#pragma once

#include <vector>
#include <map>
#include <string>

class PlatesBetweenCandles
{
public:
    std::vector<int> platesBetweenCandles(std::string s, std::vector<std::vector<int>> &queries)
    {
        std::map<int, int> candleMap;
        std::vector<int> platesInBetween;
        for (auto idx = 0, count = 0; idx < s.length(); ++idx)
        {
            if (s[idx] == '|')
            {
                candleMap.emplace(std::make_pair(idx, ++count));
            }
        }
        for (const auto &query : queries)
        {
            const auto lower = query[0];
            const auto upper = query[1];
            if ((upper - lower) < 2)
            {
                platesInBetween.push_back(0);
                continue;
            }
            auto itr_lower = candleMap.lower_bound(lower);
            if (itr_lower == candleMap.end())
            {
                platesInBetween.push_back(0);
                continue;
            }
            auto itr_upper = candleMap.upper_bound(upper);
            if (itr_upper == itr_lower)
            {
                platesInBetween.push_back(0);
                continue;
            }
            --itr_upper; // since upper_bound gives the entry key > value
            if (itr_upper == itr_lower)
            {
                platesInBetween.push_back(0);
                continue;
            }
            const auto candles = itr_upper->second - itr_lower->second - 1;
            const auto plates = itr_upper->first - itr_lower->first - 1 - candles;
            (plates >= 0) ? platesInBetween.push_back(plates) : platesInBetween.push_back(0);
        }
        return platesInBetween;
    }
};
