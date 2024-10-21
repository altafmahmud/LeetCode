#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <algorithm>
#include <iterator>
#include <string>
#include <sstream>

// 4. Median of Two Sorted Arrays
// Difficulty level: Hard

// Problem:
// Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
// The overall run time complexity should be O(log (m+n)).

// Example 1:
// Input: nums1 = [1,3], nums2 = [2]
// Output: 2.00000
// Explanation: merged array = [1,2,3] and median is 2.

// Example 2:
// Input: nums1 = [1,2], nums2 = [3,4]
// Output: 2.50000
// Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

// Constraints:

// nums1.length == m
// nums2.length == n
// 0 <= m <= 1000
// 0 <= n <= 1000
// 1 <= m + n <= 2000
// -106 <= nums1[i], nums2[i] <= 106

class MedianTwoSortedArrays
{
public:
    double findMedianSortedArrays(const std::vector<int> &nums1, const std::vector<int> &nums2)
    {
        std::vector<int> result;
        result.reserve(nums1.size() + nums2.size());
        std::merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), std::back_inserter(result));
        std::cout << "merged array = [";
        std::copy(result.begin(), result.end() - 1, std::ostream_iterator<int>(std::cout, ","));
        std::cout << result.at(result.size() - 1) << ']';
        std::cout << " and median is ";
        double median = 0.0;
        if (result.size() % 2 == 0)
        {
            const unsigned second_idx = result.size() / 2;
            const unsigned first_idx = second_idx - 1;
            const double first_val = static_cast<double>(result.at(first_idx));
            const double second_val = static_cast<double>(result.at(second_idx));
            median = (first_val + second_val) / 2.0;
            std::cout << "(" << result.at(first_idx) << " + " << result.at(second_idx) << ")" << " / 2 = " << median << '\n';
        }
        else
        {
            const unsigned idx = result.size() / 2;
            median = result.at(idx);
            std::cout << result.at(idx) << ".\n";
        }
        return median;
    }
};

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

// 3043. Find the Length of the Longest Common Prefix
// Medium
// You are given two arrays with positive integers arr1 and arr2.

// A prefix of a positive integer is an integer formed by one or more of its digits, starting from its leftmost digit.
// For example, 123 is a prefix of the integer 12345, while 234 is not.

// A common prefix of two integers a and b is an integer c, such that c is a prefix of both a and b.
// For example, 5655359 and 56554 have a common prefix 565 while 1223 and 43456 do not have a common prefix.

// You need to find the length of the longest common prefix between all pairs of integers (x, y) such that x belongs to arr1 and y belongs to arr2.

// Return the length of the longest common prefix among all pairs. If no common prefix exists among them, return 0.

// Example 1:

// Input: arr1 = [1,10,100], arr2 = [1000]
// Output: 3
// Explanation: There are 3 pairs (arr1[i], arr2[j]):
// - The longest common prefix of (1, 1000) is 1.
// - The longest common prefix of (10, 1000) is 10.
// - The longest common prefix of (100, 1000) is 100.
// The longest common prefix is 100 with a length of 3.
// Example 2:

// Input: arr1 = [1,2,3], arr2 = [4,4,4]
// Output: 0
// Explanation: There exists no common prefix for any pair (arr1[i], arr2[j]), hence we return 0.
// Note that common prefixes between elements of the same array do not count.

// Constraints:

// 1 <= arr1.length, arr2.length <= 5 * 10^4
// 1 <= arr1[i], arr2[i] <= 10^8

class LengthOfLCP
{
public:
    int longestCommonPrefix(const std::vector<int> &arr1, const std::vector<int> &arr2)
    {
        for (const auto &num : arr1)
        {
            generateAllPOssibleLCP(num);
        }
        auto maxLen = 0;
        for (const auto num : arr2)
        {
            auto n = num;
            while (n > 0)
            {
                auto itr = LCPlen.find(n);
                if (itr != LCPlen.end())
                {
                    auto len = itr->second;
                    maxLen = (len > maxLen) ? len : maxLen;
                }
                n /= 10;
            }
        }
        return maxLen;
    }

private:
    int generateAllPOssibleLCP(const int num)
    {
        auto n = num;
        std::vector<int> lcpVec;
        lcpVec.emplace_back(n);
        while (n > 0)
        {
            n /= 10;
            if (n > 0)
            {
                lcpVec.emplace_back(n);
            }
        }
        return insertIntoLCPMap(lcpVec.size(), lcpVec);
    }

    int insertIntoLCPMap(const unsigned len, const std::vector<int> &lcpVec)
    {
        auto count = 0;
        auto l = len;
        for (const auto elem : lcpVec)
        {
            if (LCPlen.emplace(std::make_pair(elem, l)).second)
            {
                ++count;
            }
            --l;
        }
        return count;
    }

    std::unordered_map<int, int> LCPlen;
};

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

// 2696. Minimum String Length After Removing Substrings
// Easy

// You are given a string s consisting only of uppercase English letters.

// You can apply some operations to this string where, in one operation, you can remove any occurrence of one of the substrings "AB" or "CD" from s.

// Return the minimum possible length of the resulting string that you can obtain.

// Note that the string concatenates after removing the substring and could produce new "AB" or "CD" substrings.

// Example 1:

// Input: s = "ABFCACDB"
// Output: 2
// Explanation: We can do the following operations:
// - Remove the substring "ABFCACDB", so s = "FCACDB".
// - Remove the substring "FCACDB", so s = "FCAB".
// - Remove the substring "FCAB", so s = "FC".
// So the resulting length of the string is 2.
// It can be shown that it is the minimum length that we can obtain.
// Example 2:

// Input: s = "ACBBD"
// Output: 5
// Explanation: We cannot do any operations on the string so the length remains the same.

// Constraints:

// 1 <= s.length <= 100
// s consists only of uppercase English letters.

class MinLengthAfterRemoveSubstr
{
public:
    int minLength(std::string s)
    {
        auto pos = std::string::npos;
        do
        {
            pos = s.find("AB");
            if (pos != std::string::npos)
            {
                s.erase(pos, 2);
                continue;
            }
            pos = s.find("CD");
            if (pos != std::string::npos)
            {
                s.erase(pos, 2);
            }
        } while (pos != std::string::npos);

        return s.length();
    }
};

// 1331. Rank Transform of an Array
// Easy

// Given an array of integers arr, replace each element with its rank.

// The rank represents how large the element is. The rank has the following rules:

// Rank is an integer starting from 1.
// The larger the element, the larger the rank. If two elements are equal, their rank must be the same.
// Rank should be as small as possible.

// Example 1:
// Input: arr = [40,10,20,30]
// Output: [4,1,2,3]
// Explanation: 40 is the largest element. 10 is the smallest. 20 is the second smallest. 30 is the third smallest.

// Example 2:
// Input: arr = [100,100,100]
// Output: [1,1,1]
// Explanation: Same elements share the same rank.

// Example 3:
// Input: arr = [37,12,28,9,100,56,80,5,12]
// Output: [5,3,4,2,8,6,7,1,3]

// Constraints:

// 0 <= arr.length <= 10^5
// -10^9 <= arr[i] <= 10^9

class RankArrayTransform
{
public:
    std::vector<int> arrayRankTransform(std::vector<int> &arr)
    {
        for (const auto &elem : arr)
        {
            rank.emplace(std::make_pair(elem, 0));
        }
        auto rankOrder = rank.size();
        for (auto &[key, val] : rank)
        {
            val = rankOrder--;
        }
        std::vector<int> rankVec;
        rankVec.reserve(arr.size());
        for (const auto &elem : arr)
        {
            rankVec.push_back(rank[elem]);
        }
        return rankVec;
    }

private:
    std::map<int, int, std::greater<int>> rank;
};

// 884. Uncommon Words from Two Sentences
// Easy
// A sentence is a string of single-space separated words where each word consists only of lowercase letters.
// A word is uncommon if it appears exactly once in one of the sentences, and does not appear in the other sentence.
// Given two sentences s1 and s2, return a list of all the uncommon words. You may return the answer in any order.

// Example 1:
// Input: s1 = "this apple is sweet", s2 = "this apple is sour"
// Output: ["sweet","sour"]

// Explanation:

// The word "sweet" appears only in s1, while the word "sour" appears only in s2.

// Example 2:
// Input: s1 = "apple apple", s2 = "banana"
// Output: ["banana"]

// Constraints:

// 1 <= s1.length, s2.length <= 200
// s1 and s2 consist of lowercase English letters and spaces.
// s1 and s2 do not have leading or trailing spaces.
// All the words in s1 and s2 are separated by a single space.

class UncommonWords
{
public:
    std::vector<std::string> uncommonFromSentences(std::string s1, std::string s2)
    {
        std::set<std::string> dupWordSet;
        auto wordSet1 = tokenize(s1, dupWordSet);
        auto wordSet2 = tokenize(s2, dupWordSet);
        wordSet1 = removeDuplicates(wordSet1, dupWordSet);
        wordSet2 = removeDuplicates(wordSet2, dupWordSet);
        std::vector<std::string> uncommonVec;
        uncommonVec.reserve(wordSet1.size() + wordSet2.size());
        std::set_difference(wordSet1.begin(), wordSet1.end(), wordSet2.begin(), wordSet2.end(), std::back_inserter(uncommonVec));
        std::set_difference(wordSet2.begin(), wordSet2.end(), wordSet1.begin(), wordSet1.end(), std::back_inserter(uncommonVec));
        uncommonVec.shrink_to_fit();
        return uncommonVec;
    }

private:
    std::set<std::string> tokenize(const std::string &str, std::set<std::string> &dupWordSet)
    {
        std::set<std::string> wordSet;
        std::stringstream ss(str);
        std::string word;
        while (ss >> word)
        {
            const auto isInserted = wordSet.emplace(word).second;
            if (!isInserted)
            {
                dupWordSet.emplace(word);
            }
        }
        return wordSet;
    }

    std::set<std::string> removeDuplicates(const std::set<std::string> &wordSet, const std::set<std::string> &dupWordSet)
    {
        std::set<std::string> uniqueSet;
        std::set_difference(wordSet.begin(), wordSet.end(), dupWordSet.begin(), dupWordSet.end(), std::inserter(uniqueSet, uniqueSet.begin()));
        return uniqueSet;
    }
};