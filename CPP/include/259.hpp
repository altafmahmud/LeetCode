// 259. 3 Sum Smaller
// Given an array of n integers nums and an integer target, find the number of index triplets i, j, k with 0 <= i < j < k < n
// that satisfy the condition nums[i] + nums[j] + nums[k] < target.

// Example 1:

// Input: nums = [-2,0,1,3], target = 2
// Output: 2
// Explanation: Because there are two triplets which sums are less than 2:
// [-2,0,1]
// [-2,0,3]

// Example 2:

// Input: nums = [], target = 0
// Output: 0

// Example 3:

// Input: nums = [0], target = 0
// Output: 0

// Constraints:

// n == nums.length
// 0 <= n <= 3500
// -100 <= nums[i] <= 100
// -100 <= target <= 100

#pragma once

#include <vector>
#include <algorithm>

class ThreeSumSmaller
{
public:
    int threeSumSmaller(std::vector<int> &nums, int target)
    {
        const auto length = nums.size();
        if (length <= 3)
        {
            auto sum = 0;
            for (auto i = 0; i < length; ++i)
            {
                sum += nums[i];
            }
            return (sum < target) ? 1 : 0;
        }
        std::sort(nums.begin(), nums.end());
        int count = 0;
        for (auto i = 0; i < length - 2; ++i)
        {
            count += twoSumSmaller(nums, i + 1, target - nums[i]);
        }
        return count;
    }

private:
    int twoSumSmaller(const std::vector<int> &nums, const int startIdx, const int target)
    {
        auto i = startIdx;
        auto j = nums.size() - 1;
        auto count = 0;
        while (i < j)
        {
            if (nums[i] + nums[j] < target)
            {
                count += j - i;
                ++i;
            }
            else
            {
                --j;
            }
        }
        return count;
    }
};