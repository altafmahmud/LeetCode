#ifndef FIRSTMISSINGPOSITIVE_41_HPP
#define FIRSTMISSINGPOSITIVE_41_HPP

// 41. First Missing Positive

// Hard

// Given an unsorted integer array nums. Return the smallest positive integer that is not present in nums.

// You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.

// Example 1:

// Input: nums = [1,2,0]
// Output: 3
// Explanation: The numbers in the range [1,2] are all in the array.

// Example 2:

// Input: nums = [3,4,-1,1]
// Output: 2
// Explanation: 1 is in the array but 2 is missing.

// Example 3:

// Input: nums = [7,8,9,11,12]
// Output: 1
// Explanation: The smallest positive integer 1 is missing.
 
// Constraints:
// 1 <= nums.length <= 10^5
// -2^31 <= nums[i] <= 2^31 - 1

#include <vector>
#include <unordered_set>
#include <algorithm>
#include <iterator>

class FirstMissingPositive {
public:
    int firstMissingPositive(std::vector<int>& nums) {
        std::unordered_set<int> s;
        std::copy_if(nums.cbegin(), nums.cend(), std::inserter(s, s.end()), [] (const int& e) { return e > 0; });
        for (int i = 1; i <= nums.size(); ++i) {
            if (!s.contains(i)) {
                return i;
            }
        }
        return nums.size() + 1;
    }
};

// This is the top solution
class FirstMissingPositiveTop {
public:
    int firstMissingPositive(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> ans(n, 0);

        // for(int i=0; i<n; i++) nums[i]--;

        for (int i = 0; i < n; i++) {
            if (nums[i] > 0 && nums[i] <= n) ans[nums[i] - 1]++;
        }

        for (int i = 0; i < n; i++) {
            if (ans[i] == 0) return i+1;
        }
        
        return n+1;
    }
};

#endif // FIRSTMISSINGPOSITIVE_41_HPP