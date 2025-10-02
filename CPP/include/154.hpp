#ifndef FINDMINROTSORTARR_154_HPP
#define FINDMINROTSORTARR_154_HPP

// 154. Find Minimum in Rotated Sorted Array II

// Hard

// Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,4,4,5,6,7] might become:

// [4,5,6,7,0,1,4] if it was rotated 4 times.
// [0,1,4,4,5,6,7] if it was rotated 7 times.
// Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

// Given the sorted rotated array nums that may contain duplicates, return the minimum element of this array.

// You must decrease the overall operation steps as much as possible.

// Example 1:

// Input: nums = [1,3,5]
// Output: 1

// Example 2:

// Input: nums = [2,2,2,0,1]
// Output: 0

// Constraints:

// n == nums.length
// 1 <= n <= 5000
// -5000 <= nums[i] <= 5000
// nums is sorted and rotated between 1 and n times. 

// Follow up: This problem is similar to "Find Minimum in Rotated Sorted Array", but nums may contain duplicates. Would this affect the runtime complexity? How and why?

#include <vector>

using namespace std;

class FindMinRotSortArrII {
public:
    int findMin(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        if (nums.size() == 2) {
            return (nums[0] < nums[1]) ? nums[0] : nums[1];
        }        
        if (nums[0] < nums[nums.size() - 1]) {
            return nums[0];
        }
        return modifiedBSearch(nums);
    }

private:
    int modifiedBSearch(const vector<int>& nums) {
        auto low = 0;
        auto high = nums.size() - 1;
        while (low < high) {
            auto sum = low + high;
            auto mid = ((sum % 2) == 0) ? sum / 2 : sum / 2 + 1;
            if (mid == high) {
                if (nums[mid] < nums[mid - 1]) {
                    return nums[mid];
                }
                --high;
            } else if (nums[mid] < nums[high]) {
                if (nums[mid] < nums[mid - 1]) {
                    return nums[mid];
                }
                high = mid - 1;
            } else if (nums[mid] > nums[high]) {
                low = mid + 1;
            } else if (nums[mid] == nums[high]) {
                --high;
            }
        }
        return nums[low];
    }
};

#endif // FINDMINROTSORTARR_154_HPP