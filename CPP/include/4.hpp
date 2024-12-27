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

#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

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