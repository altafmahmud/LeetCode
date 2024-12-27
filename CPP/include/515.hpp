// 515. Find Largest Value in Each Tree Row
// Medium
// Given the root of a binary tree, return an array of the largest value in each row of the tree (0-indexed).

// Example 1:

//         1
//         /\
//        /  \
//       3    2
//      /\     \
//     /  \     \
//    5    3     9

// Input: root = [1,3,2,5,3,null,9]
// Output: [1,3,9]

// Example 2:

// Input: root = [1,2,3]
// Output: [1,3]

// Constraints:

// The number of nodes in the tree will be in the range [0, 10^4].
// -2^31 <= Node.val <= 2^31 - 1

#pragma once

#include <vector>
#include <string>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class LargestValueInEachRowBTree
{
public:
    ~LargestValueInEachRowBTree()
    {
        clear();
    }

    // only this method is the part of the actual solution
    std::vector<int> largestValues(TreeNode *root)
    {
        std::vector<int> maxVec;
        if (root == nullptr)
        {
            return maxVec;
        }
        int max = 0;
        std::vector<TreeNode *> parentsVec, childrenVec;
        parentsVec.push_back(root);
        while (!parentsVec.empty())
        {
            max = parentsVec.at(0)->val;
            childrenVec.clear();
            childrenVec.reserve(parentsVec.size() * 2);
            for (const auto p_node : parentsVec)
            {
                if (p_node == nullptr)
                {
                    continue;
                }
                max = (p_node->val > max) ? p_node->val : max;
                if (p_node->left != nullptr)
                {
                    childrenVec.push_back(p_node->left);
                }
                if (p_node->right != nullptr)
                {
                    childrenVec.push_back(p_node->right);
                }
            }
            maxVec.push_back(max);
            parentsVec = childrenVec;
        }
        return maxVec;
    }

    TreeNode *buildTree(std::vector<std::string> strVec)
    {
        if (strVec.empty())
        {
            return nullptr;
        }
        clear();
        treeNodeVec.reserve(strVec.size());
        for (const auto &str : strVec)
        {
            if (str == "null")
            {
                treeNodeVec.push_back(nullptr);
                continue;
            }
            auto val = std::stoi(str);
            auto p_node = new TreeNode(val);
            treeNodeVec.push_back(p_node);
        }
        treeNodeVec.shrink_to_fit();
        for (auto idx = 0; idx < treeNodeVec.size(); ++idx)
        {
            auto p_node = treeNodeVec[idx];
            const auto left_child_idx = 2 * idx + 1;
            if (left_child_idx >= treeNodeVec.size())
            {
                break;
            }
            p_node->left = treeNodeVec[left_child_idx];
            const auto right_child_idx = 2 * idx + 2;
            if (right_child_idx >= treeNodeVec.size())
            {
                break;
            }
            p_node->right = treeNodeVec[right_child_idx];
        }
        return treeNodeVec[0];
    }

    void clear()
    {
        for (auto p_node : treeNodeVec)
        {
            if (p_node != nullptr)
            {
                delete p_node;
                p_node = nullptr;
            }
        }
        treeNodeVec.clear();
    }

private:
    std::vector<TreeNode *> treeNodeVec;
};