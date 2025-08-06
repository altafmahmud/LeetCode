
// 22. Generate Parentheses
// Medium

// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

// Example 1:

// Input: n = 3
// Output: ["((()))","(()())","(())()","()(())","()()()"]

// Example 2:

// Input: n = 1
// Output: ["()"]

// Constraints:
// 1 <= n <= 8

#pragma once

#include <vector>
#include <string>

class GenerateParentheses {
public:
    std::vector<std::string> generateParenthesis(int n) {
        if (n == 0) {
            return std::vector<std::string>{""};
        }
        std::vector<std::string> answer;
        for (int leftCount = 0; leftCount < n; ++leftCount) {
            for (std::string leftString : generateParenthesis(leftCount)) {
                for (std::string rightString : generateParenthesis(n - 1 - leftCount)) {
                    answer.push_back("(" + leftString + ")" + rightString);
                }
            }
        }
        return answer;
    }
};
