#ifndef REMOVEDUPLICATESFROMSORTEDLIST_82_HPP
#define REMOVEDUPLICATESFROMSORTEDLIST_82_HPP

// 82. Remove Duplicates from Sorted List II

// Medium

// Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. 
// Return the linked list sorted as well.
 
// Example 1:

// Input: head = [1,2,3,3,4,4,5]
// Output: [1,2,5]

// Example 2:

// Input: head = [1,1,1,2,3]
// Output: [2,3]
 
// Constraints:

// The number of nodes in the list is in the range [0, 300].
// -100 <= Node.val <= 100
// The list is guaranteed to be sorted in ascending order.

#include <vector>
#include <iostream>

class RemDupSortedLst {
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* node00 = nullptr;
        auto node01 = head;
        auto node02 = node01;
        while (node02 != nullptr) {
            while (node02->next != nullptr && node02->next->val == node02->val) {
                node02 = node02->next;
            }
            if (node02 != node01) {
                node02 = node02->next;
                while (node01 != node02) {
                    auto prev = node01;
                    node01 = node01->next;
                    delete prev;
                }
                (node00 == nullptr) ? head = node01 : node00->next = node01;
            } else {
                node00 = node01;
                node01 = node01->next;
                node02 = node01;
            }
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

#endif // REMOVEDUPLICATESFROMSORTEDLIST_82_HPP