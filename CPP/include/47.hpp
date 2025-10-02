#ifndef PERMUTATIONSII_47_HPP
#define PERMUTATIONSII_47_HPP

// 47. Permutations II

// Medium

// Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.

// Example 1:

// Input: nums = [1,1,2]
// Output:
// [[1,1,2],
//  [1,2,1],
//  [2,1,1]]

// Example 2:

// Input: nums = [1,2,3]
// Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]] 

// Constraints:

// 1 <= nums.length <= 8
// -10 <= nums[i] <= 10

// Taken from editorial
// ********************

#include <vector>
#include <unordered_map>

using namespace std;

class PermutationsII {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> results;
        unordered_map<int, int> counter;
        for (int num : nums) counter[num]++;
        vector<int> comb;
        backtrack(counter, comb, nums.size(), results);
        return results;
    }

private:
    void backtrack(unordered_map<int, int>& counter, vector<int>& comb, int N, vector<vector<int>>& results) {
        if (comb.size() == N) {
            results.push_back(comb);
            return;
        }
        for (auto& item : counter) {
            int num = item.first;
            int count = item.second;
            if (count == 0) {
                continue;
            }
            comb.push_back(num);
            counter[num]--;
            backtrack(counter, comb, N, results);
            comb.pop_back();
            counter[num]++;
        }
    }
};

#endif // PERMUTATIONSII_47_HPP
