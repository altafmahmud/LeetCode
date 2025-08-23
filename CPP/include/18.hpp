#ifndef KSUM_HPP
#define KSUM_HPP

// 18. 4Sum

// Medium

// Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

// 0 <= a, b, c, d < n
// a, b, c, and d are distinct.
// nums[a] + nums[b] + nums[c] + nums[d] == target
// You may return the answer in any order.

// Example 1:

// Input: nums = [1,0,-1,0,-2,2], target = 0
// Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

// Example 2:

// Input: nums = [2,2,2,2,2], target = 8
// Output: [[2,2,2,2]]

// Constraints:

// 1 <= nums.length <= 200
// -10^9 <= nums[i] <= 10^9
// -10^9 <= target <= 10^9

#include <vector>
#include <numeric>
#include <algorithm>

class KSum {
public:
    // Note: this solution also includes generalized KSum function
    // This is not an optimal solution, beats only 5%

    std::vector<std::vector<int>> ksum(std::vector<int>& nums, const int k, const int target) {
        std::vector<std::vector<int>> res_vec;
        if (nums.size() > 1) {
            std::sort(nums.begin(), nums.end());
        }
        const int limit = nums.size() - k;
        if (limit == 0) {
            constexpr long init = 0;
            const long sum = std::accumulate(nums.begin(), nums.end(), init);
            if (sum == target) {
                res_vec.push_back(nums);
                return res_vec;
            }
        }
        res_vec = recursive_ksum(nums, 0, k, target);
        std::sort(res_vec.begin(), res_vec.end());
        auto last_itr = std::unique(res_vec.begin(), res_vec.end());
        res_vec.erase(last_itr, res_vec.end());
        return res_vec;
    }

    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, const int target) {
        std::vector<std::vector<int>> res_vec;
        if (nums.size() > 1) {
            std::sort(nums.begin(), nums.end());
        }
        const int limit = nums.size() - 4;
        if (limit == 0) {
            constexpr long init = 0;
            const long sum = std::accumulate(nums.begin(), nums.end(), init);
            if (sum == target) {
                res_vec.push_back(nums);
                return res_vec;
            }
        }
        res_vec = recursive_ksum(nums, 0, 4, target);
        std::sort(res_vec.begin(), res_vec.end());
        auto last_itr = std::unique(res_vec.begin(), res_vec.end());
        res_vec.erase(last_itr, res_vec.end());
        return res_vec;
    }    

private:
    std::vector<std::vector<int>> recursive_ksum(const std::vector<int>& nums, const int startIdx, const int k, const long target) {
        std::vector<std::vector<int>> res_vec;
        if (k == 2) {
            res_vec = twoSum(nums, startIdx, target);
            return res_vec;
        }
        const int limit = nums.size() - k;
        for (auto i = startIdx; i <= limit; ++i) {
            const auto num = nums[i];
            auto ret_vec = recursive_ksum(nums, i + 1, k - 1, target - num);
            if (!ret_vec.empty()) {
                for (auto& vec : ret_vec) {
                    vec.insert(vec.begin(), num);
                    res_vec.push_back(vec);
                }
            }
        }
        return res_vec;
    }

    std::vector<std::vector<int>> twoSum(const std::vector<int>& nums, const int startIdx, const long target) {
        std::vector<std::vector<int>> res;
        auto low = startIdx;
        auto high = nums.size() - 1;
        while (low < high) {
            const long sum = nums[low] + nums[high];
            if (sum == target) {
                std::vector<int> vec;
                vec.push_back(nums[low]);
                vec.push_back(nums[high]);
                res.push_back(vec);
                --high;
            } else if (sum > target) {
                --high;
            } else {
                ++low;
            }
        }
        return res;
    }
};

#endif // KSUM_HPP
