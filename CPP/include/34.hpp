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

#pragma once

#include <vector>

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
