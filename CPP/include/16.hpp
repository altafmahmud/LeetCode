// 16. 3Sum Closest
// Medium
// Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.

// Return the sum of the three integers.

// You may assume that each input would have exactly one solution.

// Example 1:

// Input: nums = [-1,2,1,-4], target = 1
// Output: 2
// Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

// Example 2:

// Input: nums = [0,0,0], target = 1
// Output: 0
// Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).

// Constraints:

// 3 <= nums.length <= 500
// -1000 <= nums[i] <= 1000
// -10^4 <= target <= 10^4

#pragma once

#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>

constexpr int maxDiff = std::numeric_limits<int>::max();

class ThreeSumClosest
{
public:
    int threeSumClosest(std::vector<int> &nums, int target)
    {
        auto three_sum_closest = 0;
        auto diff = maxDiff;
        std::sort(nums.begin(), nums.end());
        for (auto idx = 0; idx < nums.size() - 2; ++idx)
        {
            auto three_sum = nums[idx] + twoSumClosest(nums, idx + 1, target - nums[idx]);
            auto curr_diff = std::abs(target - three_sum);
            if (curr_diff < diff)
            {
                diff = curr_diff;
                three_sum_closest = three_sum;
            }
        }
        return three_sum_closest;
    }

private:
    int twoSumClosest(const std::vector<int> &nums, const unsigned startIdx, const int target)
    {
        auto idx = startIdx;
        auto jdx = nums.size() - 1;
        auto closest_sum = 0;
        int diff = maxDiff;
        while (idx < jdx)
        {
            auto sum = nums[idx] + nums[jdx];
            auto curr_diff = std::abs(target - sum);
            if (curr_diff == 0)
            {
                closest_sum = sum;
                break;
            }
            if (curr_diff < diff)
            {
                diff = curr_diff;
                closest_sum = sum;
            }
            (sum < target) ? ++idx : --jdx;
        }
        return closest_sum;
    }
};