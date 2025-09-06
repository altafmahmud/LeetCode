#ifndef MERGETWOSORTEDLIST_21_HPP
#define MERGETWOSORTEDLIST_21_HPP

// 21. Merge Two Sorted Lists

// Easy

// You are given the heads of two sorted linked lists list1 and list2.
// Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.
// Return the head of the merged linked list.

// Example 1:
// [Image ref.: 21.jpg]
// Input: list1 = [1,2,4], list2 = [1,3,4]
// Output: [1,1,2,3,4,4]

// Example 2:

// Input: list1 = [], list2 = []
// Output: []

// Example 3:

// Input: list1 = [], list2 = [0]
// Output: [0]
 
// Constraints:

// The number of nodes in both lists is in the range [0, 50].
// -100 <= Node.val <= 100
// Both list1 and list2 are sorted in non-decreasing order.

#include <vector>
#include <ostream>

class MergeTwoSortedList {
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) {
            return list2;
        }
        if (list2 == nullptr) {
            return list1;
        }        
        ListNode* prev1 = nullptr;
        ListNode* prev2 = nullptr;
        auto curr1 = list1;
        auto curr2 = list2;
        while (curr1 != nullptr & curr2 != nullptr) {
            if (curr1->val < curr2->val) {
                auto next1 = curr1->next;
                curr1->next = curr2;
                if (prev1 != nullptr) {
                    prev1->next = next1;
                }
                if (prev2 != nullptr) {
                    prev2->next = curr1;
                    prev2 = prev2->next;
                } else {
                    list2 = prev2 = curr1;
                }
                curr1 = next1;
            } else if (curr1->val == curr2->val) {
                auto next1 = curr1->next;
                auto next2 = curr2->next;
                curr2->next = curr1;
                curr1->next = next2;
                if (prev1 != nullptr) {
                    prev1->next = next1;
                }
                curr1 = next1;
                prev2 = curr2;
                curr2 = curr2->next;
            } else {
                prev2 = curr2;
                curr2 = curr2->next;
            }
        }
        if (curr2 == nullptr & curr1 != nullptr) {
            prev2->next = curr1;
            prev1 = nullptr;
        }
        return list2;
    }

    ListNode* buildList(const std::vector<short>& data) {
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

#endif // MERGETWOSORTEDLIST_21_HPP