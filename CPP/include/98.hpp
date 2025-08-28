#ifndef VALIDBST_HPP
#define VALIDBST_HPP

// 98. Validate Binary Search Tree

// Medium

// Given the root of a binary tree, determine if it is a valid binary search tree (BST).

// A valid BST is defined as follows:

// The left subtree of a node contains only nodes with keys strictly less than the node's key.
// The right subtree of a node contains only nodes with keys strictly greater than the node's key.
// Both the left and right subtrees must also be binary search trees.
 
// Example 1:

// Input: root = [2,1,3]
// Output: true
// Image ref. 98_01.jpg

// Example 2:

// Input: root = [5,1,4,null,null,3,6]
// Output: false
// Explanation: The root node's value is 5 but its right child's value is 4.
// Image ref. 98_02.jpg

// Constraints:

// The number of nodes in the tree is in the range [1, 104].
// -2^31 <= Node.val <= 2^31 - 1

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

namespace {
constexpr long MIN = std::numeric_limits<int>::min();
}

class ValidBST {
public:
    // Definition for a binary tree node.
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

    TreeNode* buildTree(const std::vector<long>& elem) {
        std::cout << "Building tree...\n";
        std::vector<TreeNode*> tree_node_vec(elem.size());
        std::fill(tree_node_vec.begin(), tree_node_vec.end(), nullptr);
        for (auto i = 0; i < elem.size(); ++i) {
            const auto l_child_idx = (2*i) + 1;
            const auto r_child_idx = (2*i) + 2;
            const auto val = elem[i];
            if (val < MIN) {
                continue;
            }
            if (tree_node_vec[i] == nullptr) {
                tree_node_vec[i] = new TreeNode(val);
            }
            std::cout << "Node: " << val;
            if (l_child_idx < elem.size()) {
                const auto l_child_val = elem[l_child_idx];
                if (l_child_val < MIN) {
                    tree_node_vec[i]->left = nullptr;
                    std::cout << " Left child: NULL";
                } else {
                    tree_node_vec[l_child_idx] = new TreeNode(l_child_val);
                    tree_node_vec[i]->left = tree_node_vec[l_child_idx];
                    std::cout << " Left child: " << l_child_val;
                }
                if (r_child_idx < elem.size())
                {
                    const auto r_child_val = elem[r_child_idx];
                    if (r_child_val < MIN)
                    {
                        tree_node_vec[i]->right = nullptr;
                        std::cout << " Right child: NULL";
                    }
                    else
                    {
                        tree_node_vec[r_child_idx] = new TreeNode(r_child_val);
                        tree_node_vec[i]->right = tree_node_vec[r_child_idx];
                        std::cout << " Right child: " << r_child_val;
                    }
                }
            }
            else {
                break;
            }
            std::cout << '\n';
        }
        return tree_node_vec[0];
    }

    void deleteTree(TreeNode* root) {
        auto l_child = root->left;
        auto r_child = root->right;
        if (l_child != nullptr) {
            deleteTree(l_child);
        }
        if (r_child != nullptr) {
            deleteTree(r_child);
        }
        const auto val = root->val;
        delete root;
        root = nullptr;
        std::cout << "Node: " << val << " deleted\n";
    }

    bool isValidBST(TreeNode* root) {
        return checkValidity(root, nullptr, nullptr);
    }

private:
    bool checkValidity(TreeNode* root, int* lowerLimit, int* higherLimit) {
        if (lowerLimit != nullptr && root->val <= *lowerLimit) {
            return false;
        }
        if (higherLimit != nullptr && root->val >= *higherLimit) {
            return false;
        }
        const auto l_child = root->left;
        const auto r_child = root->right;
        if (l_child != nullptr) {
            auto& new_higher_limit = root->val;
            if (!checkValidity(l_child, lowerLimit, &new_higher_limit)) {
                return false;
            }
        }
        if (r_child != nullptr) {
            auto& new_lower_limit = root->val;
            if (!checkValidity(r_child, &new_lower_limit, higherLimit)) {
                return false;
            }
        }        
        return true;
    }
};

#endif // VALIDBST_HPP