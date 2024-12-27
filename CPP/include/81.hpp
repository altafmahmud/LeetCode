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

#pragma once

#include <vector>

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
