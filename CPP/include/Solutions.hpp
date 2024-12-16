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
#include <cstdlib>
#include <numeric>

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

// 1208. Get Equal Substrings Within Budget
// Medium
// You are given two strings s and t of the same length and an integer maxCost.
// You want to change s to t. Changing the ith character of s to ith character of t costs |s[i] - t[i]| (i.e., the absolute difference between the ASCII values of the characters).
// Return the maximum length of a substring of s that can be changed to be the same as the corresponding substring of t with a cost less than or equal to maxCost.
// If there is no substring from s that can be changed to its corresponding substring from t, return 0.

// Example 1:
// Input: s = "abcd", t = "bcdf", maxCost = 3
// Output: 3
// Explanation: "abc" of s can change to "bcd".
// That costs 3, so the maximum length is 3.

// Example 2:
// Input: s = "abcd", t = "cdef", maxCost = 3
// Output: 1
// Explanation: Each character in s costs 2 to change to character in t,  so the maximum length is 1.

// Example 3:
// Input: s = "abcd", t = "acde", maxCost = 0
// Output: 1
// Explanation: You cannot make any change, so the maximum length is 1.

// Constraints:
// 1 <= s.length <= 10^5
// t.length == s.length
// 0 <= maxCost <= 10^6
// s and t consist of only lowercase English letters.

class EqualSubstrInBudget
{
public:
    int equalSubstring(std::string s, std::string t, int maxCost)
    {
        auto binOp = [](const auto val1, const auto val2) -> unsigned
        {
            return std::abs(val1 - val2);
        };
        std::vector<unsigned> diff;
        diff.reserve(s.length());
        std::transform(t.begin(), t.end(), s.begin(), std::back_inserter(diff), binOp);
        const auto sum = std::accumulate(diff.begin(), diff.end(), 0);
        if (sum <= maxCost)
        {
            return s.length();
        }
        auto maxLen = 0;
        auto idx1 = 0;
        auto idx2 = 0;
        auto len = 0;
        while (idx1 < diff.size() - 1)
        {
            if (s.length() - idx1 <= maxLen)
            {
                break;
            }
            auto cost = diff[idx1];
            len = 0;
            idx2 = idx1 + 1;
            while (idx2 < diff.size() && cost <= maxCost)
            {
                if (cost + diff[idx2] <= maxCost)
                {
                    cost += diff[idx2];
                }
                else
                {
                    len = idx2 - idx1;
                    maxLen = (len > maxLen) ? len : maxLen;
                    break;
                }
                ++idx2;
            }
            if (idx2 >= diff.size())
            {
                len = idx2 - idx1;
                maxLen = (len > maxLen) ? len : maxLen;
                break;
            }
            ++idx1;
        }
        return maxLen;
    }
};

// 26. Remove Duplicates from Sorted Array
// Easy
// Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once.
// The relative order of the elements should be kept the same. Then return the number of unique elements in nums.

// Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things:

// - Change the array nums such that the first k elements of nums contain the unique elements in the order they were present in nums initially.
//   The remaining elements of nums are not important as well as the size of nums.
// - Return k.

// Custom Judge:

// The judge will test your solution with the following code:

// int[] nums = [...]; // Input array
// int[] expectedNums = [...]; // The expected answer with correct length

// int k = removeDuplicates(nums); // Calls your implementation

// assert k == expectedNums.length;
// for (int i = 0; i < k; i++) {
//     assert nums[i] == expectedNums[i];
// }
// If all assertions pass, then your solution will be accepted.

// Example 1:

// Input: nums = [1,1,2]
// Output: 2, nums = [1,2,_]
// Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
// It does not matter what you leave beyond the returned k (hence they are underscores).

// Example 2:

// Input: nums = [0,0,1,1,1,2,2,3,3,4]
// Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
// Explanation: Your function should return k = 5, with the first five elements of nums being 0, 1, 2, 3, and 4 respectively.
// It does not matter what you leave beyond the returned k (hence they are underscores).

// Constraints:

// 1 <= nums.length <= 3 * 104
// -100 <= nums[i] <= 100
// nums is sorted in non-decreasing order.

class RemDupSortedArr
{
public:
    int removeDuplicates(std::vector<int> &nums)
    {
        std::unordered_set<int> s;
        auto non_exist_num = nums.at(0) - 1;
        for (auto &num : nums)
        {
            if (s.count(num) == 0)
            {
                s.insert(num);
            }
            else
            {
                num = non_exist_num;
            }
        }
        nums.erase(std::remove_if(nums.begin(), nums.end(), [&non_exist_num](const auto num)
                                  { return num == non_exist_num; }),
                   nums.end());
        nums.shrink_to_fit();
        return nums.size();
    }
};

// 27. Remove Element
// Easy
// Given an integer array nums and an integer val, remove all occurrences of val in nums in-place.
// The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.

// Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things:

// - Change the array nums such that the first k elements of nums contain the elements which are not equal to val.
//   The remaining elements of nums are not important as well as the size of nums.
// - Return k.

// Custom Judge:

// The judge will test your solution with the following code:

// int[] nums = [...]; // Input array
// int val = ...; // Value to remove
// int[] expectedNums = [...]; // The expected answer with correct length.
//                             // It is sorted with no values equaling val.

// int k = removeElement(nums, val); // Calls your implementation

// assert k == expectedNums.length;
// sort(nums, 0, k); // Sort the first k elements of nums
// for (int i = 0; i < actualLength; i++) {
//     assert nums[i] == expectedNums[i];
// }
// If all assertions pass, then your solution will be accepted.

// Example 1:

// Input: nums = [3,2,2,3], val = 3
// Output: 2, nums = [2,2,_,_]
// Explanation: Your function should return k = 2, with the first two elements of nums being 2.
// It does not matter what you leave beyond the returned k (hence they are underscores).

// Example 2:

// Input: nums = [0,1,2,2,3,0,4,2], val = 2
// Output: 5, nums = [0,1,4,0,3,_,_,_]
// Explanation: Your function should return k = 5, with the first five elements of nums containing 0, 0, 1, 3, and 4.
// Note that the five elements can be returned in any order.
// It does not matter what you leave beyond the returned k (hence they are underscores).

// Constraints:
// 0 <= nums.length <= 100
// 0 <= nums[i] <= 50
// 0 <= val <= 100

class RemElement
{
public:
    int removeElement(std::vector<int> &nums, int val)
    {
        auto jdx = 0;
        for (auto idx = 0; idx < nums.size(); ++idx)
        {
            if (nums[idx] == val)
            {
                continue;
            }
            nums[jdx] = nums[idx];
            ++jdx;
        }
        return jdx;
    }
};

// 29. Divide Two Integers
// Medium
// Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.

// The integer division should truncate toward zero, which means losing its fractional part. For example, 8.345 would be truncated to 8, and -2.7335 would be truncated to -2.

// Return the quotient after dividing dividend by divisor.

// Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−2^31, 2^31 − 1].
// For this problem, if the quotient is strictly greater than 2^31 - 1, then return 2^31 - 1, and if the quotient is strictly less than -2^31, then return -2^31.

// Example 1:

// Input: dividend = 10, divisor = 3
// Output: 3
// Explanation: 10/3 = 3.33333.. which is truncated to 3.

// Example 2:

// Input: dividend = 7, divisor = -3
// Output: -2
// Explanation: 7/-3 = -2.33333.. which is truncated to -2.

// Constraints:

// > -231 <= dividend, divisor <= 231 - 1
// > divisor != 0

class DivideTwoInt
{
public:
    int divide(int dividend, int divisor)
    {
        if (dividend == 0)
        {
            return 0;
        }
        const auto min_32 = std::numeric_limits<int32_t>::min();
        const auto max_32 = std::numeric_limits<int32_t>::max();
        auto negative = (dividend < 0) ^ (divisor < 0);
        int32_t quotient = 0;
        unsigned abs_dividend = (dividend < 0) ? std::labs(dividend) : dividend;
        unsigned abs_divisor = (divisor < 0) ? std::labs(divisor) : divisor;
        if (abs_dividend < abs_divisor)
        {
            return 0;
        }
        if (abs_divisor == 1)
        {
            if (negative)
            {
                return (dividend < 0) ? dividend : -dividend;
            }
            else if (dividend < 0)
            {
                if (dividend == min_32)
                {
                    return max_32;
                }
                return static_cast<int32_t>(abs_dividend);
            }
        }
        if (abs_dividend == abs_divisor)
        {
            return (negative) ? -1 : 1;
        }
        while (abs_dividend >= abs_divisor)
        {
            unsigned temp_abs_divisor = abs_divisor;
            unsigned multiple = 1;
            while (abs_dividend >= (temp_abs_divisor << 1))
            {
                temp_abs_divisor <<= 1;
                multiple <<= 1;
                if (abs_dividend == temp_abs_divisor)
                {
                    break;
                }
            }
            abs_dividend -= temp_abs_divisor;
            quotient += multiple;
        }
        return (negative) ? -quotient : quotient;
    }
};

// 33. Search in Rotated Sorted Array
// Medium
// There is an integer array nums sorted in ascending order (with distinct values).

// Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that
// the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed).
// For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

// Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

// You must write an algorithm with O(log n) runtime complexity.

// Example 1:

// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4
// Example 2:

// Input: nums = [4,5,6,7,0,1,2], target = 3
// Output: -1
// Example 3:

// Input: nums = [1], target = 0
// Output: -1

// Constraints:

// > 1 <= nums.length <= 5000
// > -10^4 <= nums[i] <= 10^4
// > All values of nums are unique.
// > nums is an ascending array that is possibly rotated.
// > -10^4 <= target <= 10^4

class SearchInRotatedSortedArr
{
public:
    int search(std::vector<int> &nums, int target)
    {
        if (isPivoted(nums))
        {
            if (nums[0] == target)
            {
                return 0;
            }
            const auto pivot_idx = getPivotIndex(nums);
            return (target < nums[0]) ? BSearch(nums, pivot_idx, nums.size() - 1, target) : BSearch(nums, 0, pivot_idx - 1, target);
        }
        return BSearch(nums, 0, nums.size() - 1, target);
    }

private:
    bool isPivoted(const std::vector<int> &nums) const
    {
        const auto len = nums.size();
        return nums[len - 1] < nums[0];
    }

    int getPivotIndex(const std::vector<int> &nums)
    {
        int left = 0;
        int right = nums.size() - 1;
        int mid = left + (right - left) / 2;
        while (left < right)
        {
            if (nums[mid] > nums[right])
            {
                left = mid + 1;
            }
            else
            {
                if (nums[mid - 1] < nums[mid])
                {
                    right = mid - 1;
                }
                else
                {
                    break;
                }
            }
            mid = left + (right - left) / 2;
        }
        return mid;
    }

    int BSearch(const std::vector<int> &nums, int left, int right, int target)
    {
        while (left <= right)
        {
            if (left == right)
            {
                return (nums[left] == target) ? left : -1;
            }
            auto mid = left + (right - left) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            (nums[mid] < target) ? left = mid + 1 : right = mid - 1;
        }
        return -1;
    }
};

// 81. Search in Rotated Sorted Array II
// Medium
// There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).

// Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is
// [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed).
// For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].

// Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it is not in nums.

// You must decrease the overall operation steps as much as possible.

// Example 1:

// Input: nums = [2,5,6,0,0,1,2], target = 0
// Output: true

// Example 2:

// Input: nums = [2,5,6,0,0,1,2], target = 3
// Output: false

// Constraints:

// > 1 <= nums.length <= 5000
// > -10^4 <= nums[i] <= 10^4
// > nums is guaranteed to be rotated at some pivot.
// > -10^4 <= target <= 10^4

// Follow up: This problem is similar to Search in Rotated Sorted Array, but nums may contain duplicates. Would this affect the runtime complexity? How and why?

// This solution is done from editorial

class SearchInRotatedSortedArrII
{
public:
    bool search(const std::vector<int> &nums, int target)
    {
        return BSearch(nums, 0, nums.size() - 1, target);
    }

private:
    bool BSearch(const std::vector<int> &nums, int left, int right, int target)
    {
        while (left <= right)
        {
            if (left == right)
            {
                return (nums[left] == target) ? true : false;
            }
            auto mid = left + (right - left) / 2;
            if (nums[mid] == target)
            {
                return true;
            }
            if (!isBSearchUseful(nums, left, mid))
            {
                ++left;
                continue;
            }

            // which array does pivot belongs to
            const auto pivotInArr = existInFirstPortion(nums, left, nums[mid]);
            // which array does target belongs to
            const auto targetInArr = existInFirstPortion(nums, left, target);

            if (pivotInArr ^ targetInArr) // If pivot and target exist in different sorted arrays
            {
                // if pivot in this first array portion and target in other portion then consider the other portion
                // if target in this first array portion and pivot in other portion then consider the first portion
                // Follow the target
                (pivotInArr) ? left = mid + 1 : right = mid - 1;
            }
            else
            {
                // If pivot and target exist in same sorted array
                (nums[mid] < target) ? left = mid + 1 : right = mid - 1;
            }
            // if the left position hits the target in any chance
            if (nums[left] == target)
            {
                return true;
            }
            // if the right position hits the target in any chance
            if (nums[right] == target)
            {
                return true;
            }
        }
        return false;
    }

    // returns true if we can reduce the search space in current binary search space
    bool isBSearchUseful(const std::vector<int> &nums, const int left, const int mid) const
    {
        return nums[left] != nums[mid];
    }

    // returns true if element exists in first array, false if it exists in second
    bool existInFirstPortion(const std::vector<int> &nums, const int left, const int element) const
    {
        return nums[left] <= element;
    }
};

// 34. Find First and Last Position of Element in Sorted Array

// Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

// If target is not found in the array, return [-1, -1].

// You must write an algorithm with O(log n) runtime complexity.

// Example 1:

// Input: nums = [5,7,7,8,8,10], target = 8
// Output: [3,4]
// Example 2:

// Input: nums = [5,7,7,8,8,10], target = 6
// Output: [-1,-1]
// Example 3:

// Input: nums = [], target = 0
// Output: [-1,-1]

// Constraints:

// > 0 <= nums.length <= 10^5
// > -10^9 <= nums[i] <= 10^9
// > nums is a non-decreasing array.
// > -10^9 <= target <= 10^9

class FindFirstLastPosOfElemInSortedArray
{
public:
    std::vector<int> searchRange(std::vector<int> &nums, int target)
    {
        res = {-1, -1};
        if (nums.empty())
        {
            return res;
        }
        searchReceursively(nums, 0, nums.size() - 1, target);
        return res;
    }

private:
    int BSearch(const std::vector<int> &nums, const int start, const int end, const int target)
    {
        auto left = start;
        auto right = end;
        while (left <= right)
        {
            if (left == right)
            {
                return (nums[left] == target) ? left : -1;
            }
            if (nums[left] == target)
            {
                return left;
            }
            if (nums[right] == target)
            {
                return right;
            }
            auto mid = left + (right - left) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            (nums[mid] > target) ? right = mid - 1 : left = mid + 1;
        }
        return -1;
    }

    void searchReceursively(const std::vector<int> &nums, const int start, const int end, const int target)
    {
        if (nums[start] == target && nums[end] == target)
        {
            res[0] = (res[0] < 0 || start < res[0]) ? start : res[0];
            res[1] = (res[1] < 0 || end > res[1]) ? end : res[1];
            return;
        }
        if (end - start == 0)
        {
            return;
        }
        const auto idx = BSearch(nums, start, end, target);
        if (idx < 0)
        {
            return;
        }
        res[0] = (res[0] < 0 || idx < res[0]) ? idx : res[0];
        res[1] = (res[1] < 0 || idx > res[1]) ? idx : res[1];
        if (idx > 0)
        {
            searchReceursively(nums, 0, idx - 1, target);
        }
        if (idx < end)
        {
            searchReceursively(nums, idx + 1, end, target);
        }
    }

    std::vector<int> res;
};

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