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

#pragma once

#include <vector>

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
