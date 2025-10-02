#ifndef SWAPNODESINPAIR_24_HPP
#define SWAPNODESINPAIR_24_HPP

// 24. Swap Nodes in Pairs

// Medium

// Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes 
// themselves may be changed.)

// Example 1:

// Input: head = [1,2,3,4]
// Output: [2,1,4,3]
// Explanation: [image ref.: 24_01.jpg]

// Example 2:

// Input: head = []
// Output: []

// Example 3:

// Input: head = [1]
// Output: [1]

// Example 4:
// Input: head = [1,2,3]
// Output: [2,1,3]

// Constraints:

// The number of nodes in the list is in the range [0, 100].
// 0 <= Node.val <= 100

#include <vector>
#include <iostream>

class SwapNodesInPair {
private:
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr) {
            return head;
        }
        ListNode* node00 = nullptr;
        auto node01 = head;
        auto node02 = node01->next;
        while (node02 != nullptr) {
            node01->next = node02->next;
            node02->next = node01;
            (node00 == nullptr) ? head = node02 : node00->next = node02;
            // now proceed after swapping
            node00 = node01;
            node01 = node00->next;
            if (node01 == nullptr) {
                break;
            }
            node02 = node01->next;
        }
        return head;
    }

    ListNode* buildList(const std::vector<int>& data) {
        ListNode* head = nullptr;
        ListNode* curr = head;
        for (const auto& e : data) {
            auto node = new ListNode(e);
            if (head == nullptr) {
                head = node;
                curr = head;
            } else {
                curr->next = node;
                curr = curr->next;
            }
        }
        return head;
    }

    ListNode* deleteList(ListNode* head) {
        auto curr = head;
        while (curr != nullptr) {
            // const auto val = curr->val;
            auto next = curr->next;
            delete curr;
            // std::cout << val << " deleted\n";
            curr = next;
        }
        head = nullptr;
        return head;
    }
   
    friend std::ostream& operator<<(std::ostream& os, ListNode* head) {
        os << '[';
        for (auto curr = head; curr != nullptr; curr = curr->next) {
            os << curr->val;
            if (curr->next != nullptr) {
                os << ',';
            }
        }
        os << ']';
        return os;
    }
};

#endif // SWAPNODESINPAIR_24_HPP
