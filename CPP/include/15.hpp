// 15. 3Sum
// Medium
// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

// Notice that the solution set must not contain duplicate triplets.

// Example 1:

// Input: nums = [-1,0,1,2,-1,-4]
// Output: [[-1,-1,2],[-1,0,1]]
// Explanation:
// nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
// nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
// nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
// The distinct triplets are [-1,0,1] and [-1,-1,2].
// Notice that the order of the output and the order of the triplets does not matter.
// Example 2:

// Input: nums = [0,1,1]
// Output: []
// Explanation: The only possible triplet does not sum up to 0.
// Example 3:

// Input: nums = [0,0,0]
// Output: [[0,0,0]]
// Explanation: The only possible triplet sums up to 0.

// Constraints:

// 3 <= nums.length <= 3000
// -10^5 <= nums[i] <= 10^5

#pragma once

#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

// This appreach beats only 5%
class ThreeSum1
{
public:
    std::vector<std::vector<int>> threeSum(std::vector<int> &nums)
    {
        std::vector<std::vector<int>> res_vec;
        std::unordered_set<int> taken;
        for (auto idx = 0; idx <= nums.size() - 2; ++idx)
        {
            const auto fixed = nums[idx];
            if (taken.find(fixed) != taken.end())
            {
                continue;
            }
            taken.insert(fixed);
            const auto &two_sum_vec = twoSum(nums, idx + 1, 0 - fixed);
            for (const auto &two_sum : two_sum_vec)
            {
                std::vector<int> v(3);
                if (fixed <= two_sum[0])
                {
                    v[0] = fixed;
                    v[1] = two_sum[0];
                    v[2] = two_sum[1];
                }
                else
                {
                    if (fixed <= two_sum[1])
                    {
                        v[0] = two_sum[0];
                        v[1] = fixed;
                        v[2] = two_sum[1];
                    }
                    else
                    {
                        v[0] = two_sum[0];
                        v[1] = two_sum[1];
                        v[2] = fixed;
                    }
                }
                res_vec.push_back(v);
            }
        }
        std::sort(res_vec.begin(), res_vec.end());
        auto itr = std::unique(res_vec.begin(), res_vec.end());
        res_vec.erase(itr, res_vec.end());
        return res_vec;
    }

private:
    std::vector<std::vector<int>> twoSum(std::vector<int> &subVec, const unsigned startIdx, const int target)
    {
        std::unordered_map<int, unsigned> remain_idx_map;
        std::unordered_set<int> taken;
        std::vector<std::vector<int>> two_sum_vec;
        auto idx2 = startIdx;
        while (idx2 < subVec.size())
        {
            auto num = subVec[idx2];
            if (taken.find(num) != taken.end())
            {
                ++idx2;
                continue;
            }
            auto remain = target - num;
            auto found_itr = remain_idx_map.find(num);
            if (found_itr != remain_idx_map.end())
            {
                auto idx1 = remain_idx_map[num];
                std::vector<int> two_sum(2);
                if (subVec[idx1] <= subVec[idx2])
                {
                    two_sum[0] = subVec[idx1];
                    two_sum[1] = subVec[idx2];
                }
                else
                {
                    two_sum[1] = subVec[idx1];
                    two_sum[0] = subVec[idx2];
                }
                two_sum_vec.push_back(two_sum);
                taken.insert(subVec[idx1]);
                taken.insert(subVec[idx2]);
            }
            else
            {
                remain_idx_map.emplace(std::make_pair(remain, idx2));
            }
            ++idx2;
        }
        return two_sum_vec;
    }
};

// This better appreach beats 28.14 % with 79 ms of runtime (still not in the top list but better)
class ThreeSum
{
public:
    std::vector<std::vector<int>> threeSum(std::vector<int> &nums)
    {
        std::vector<std::vector<int>> res_vec;
        std::sort(nums.begin(), nums.end());
        auto pass_the_end = -1;
        for (auto idx = 0; idx <= nums.size() - 2; ++idx)
        {
            if (idx > 0 && nums[idx] == nums[idx - 1])
            {
                // check if the remaining numbers are all same, if so, then the solution is done
                if (pass_the_end > 0 && idx >= pass_the_end)
                {
                    break;
                }
                continue;
            }
            const auto fixed = nums[idx];
            const auto two_sum_vec = twoSum(nums, idx + 1, 0 - fixed, pass_the_end);
            for (const auto &two_sum : two_sum_vec)
            {
                std::vector<int> v(3);
                v[0] = fixed;
                v[1] = two_sum[0];
                v[2] = two_sum[1];
                res_vec.push_back(v);
            }
        }
        return res_vec;
    }

private:
    std::vector<std::vector<int>> twoSum(std::vector<int> &subVec, const unsigned startIdx, const int target, int &passTheEnd)
    {
        std::vector<std::vector<int>> two_sum_vec;
        std::vector<int> two_sum(2);
        auto idx1 = startIdx;
        auto idx2 = subVec.size() - 1;
        while (idx1 < idx2)
        {
            const auto val1 = subVec[idx1];
            const auto val2 = subVec[idx2];
            const auto sum = val1 + val2;
            if (sum == target)
            {
                two_sum[0] = val1;
                two_sum[1] = val2;
                two_sum_vec.push_back(two_sum);
                passTheEnd = idx1;
                ++idx1;
                while (subVec[idx1] == subVec[idx1 - 1] && idx1 < idx2)
                {
                    ++idx1;
                }
                if (idx1 < idx2)
                {
                    passTheEnd = -1;
                }
                if (passTheEnd == -1)
                {
                    passTheEnd = idx2;
                }
                --idx2;
                while (subVec[idx2] == subVec[idx2 + 1] && idx2 > idx1)
                {
                    --idx2;
                }
                if (idx2 > idx1)
                {
                    passTheEnd = -1;
                }
            }
            else if (sum < target)
            {
                passTheEnd = idx1;
                ++idx1;
                while (subVec[idx1] == subVec[idx1 - 1] && idx1 < idx2)
                {
                    ++idx1;
                }
                if (idx1 < idx2)
                {
                    passTheEnd = -1;
                }
            }
            else
            {
                passTheEnd = idx2;
                --idx2;
                while (subVec[idx2] == subVec[idx2 + 1] && idx2 > idx1)
                {
                    --idx2;
                }
                if (idx2 > idx1)
                {
                    passTheEnd = -1;
                }
            }
        }
        return two_sum_vec;
    }
};