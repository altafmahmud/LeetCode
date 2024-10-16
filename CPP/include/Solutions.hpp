#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iterator>

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

class MedianTwoSortedArrays {
public:
    double findMedianSortedArrays(const std::vector<int>& nums1, const std::vector<int>& nums2) {
        std::vector<int> result;
        result.reserve(nums1.size() + nums2.size());
        std::merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), std::back_inserter(result));
        std::cout << "merged array = [";
        std::copy(result.begin(), result.end()-1, std::ostream_iterator<int>(std::cout, ","));
        std::cout << result.at(result.size() - 1) << ']';
        std::cout << " and median is ";
        double median = 0.0;
        if(result.size() % 2 == 0) {
            const unsigned second_idx = result.size() / 2;
            const unsigned first_idx = second_idx - 1;
            const double first_val = static_cast<double>(result.at(first_idx));
            const double second_val = static_cast<double>(result.at(second_idx));
            median = (first_val + second_val) / 2.0;
            std::cout << "(" << result.at(first_idx) << " + " << result.at(second_idx) << ")" << " / 2 = " << median << '\n';
        }
        else {
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

class LongestCommonPrefix {
    public:
    std::string longestCommonPrefix(const std::vector<std::string>& strs)
    {
        std::string lcp("");
        char c = '\0';
        auto cond = true;
        for (unsigned col = 0; cond && col <= 200; ++col)
        {
            for (unsigned row = 0; row < strs.size(); ++row)
            {
                if (strs[row].size() ==  col)
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

class LengthOfLCP {
public:
    int longestCommonPrefix(const std::vector<int>& arr1, const std::vector<int>& arr2)
    {
        for (const auto& num : arr1)
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

    int insertIntoLCPMap(const unsigned len, const std::vector<int>& lcpVec)
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