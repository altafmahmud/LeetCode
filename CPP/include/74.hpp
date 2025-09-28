#ifndef SEARCH2DMAT_74_HPP
#define SEARCH2DMAT_74_HPP

// 74. Search a 2D Matrix

// Medium

// You are given an m x n integer matrix matrix with the following two properties:

// Each row is sorted in non-decreasing order.
// The first integer of each row is greater than the last integer of the previous row.
// Given an integer target, return true if target is in matrix or false otherwise.

// You must write a solution in O(log(m * n)) time complexity.

// Example 1:

// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
// Output: true

// Example 2:

// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
// Output: false

// Constraints:

// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 100
// -10^4 <= matrix[i][j], target <= 10^4

#include <vector>

using namespace std;

class Search2DMat {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        const auto m = matrix.size();
        const auto n = matrix.at(0).size();
        return BSearch(matrix, m, n, target);
    }

private:
    bool BSearch(const vector<vector<int>>& matrix, const int m, const int n, const int target) {
        auto low = 0;
        auto high = m * n - 1;
        while (low <= high) {
            const auto sum = low + high;
            const auto mid = ((sum % 2) == 0) ? sum / 2 : sum / 2 + 1;
            const auto i = mid / n;
            const auto j = mid % n;
            if (matrix[i][j] == target) {
                return true;
            } else if (matrix[i][j] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return false;
    }
};

#endif // SEARCH2DMAT_74_HPP