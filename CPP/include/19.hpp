#ifndef REMOVENTHNODE_19_HPP
#define REMOVENTHNODE_19_HPP

// 19. Remove Nth Node From End of List

// Medium

// Given the head of a linked list, remove the nth node from the end of the list and return its head.
 
// Example 1:
// [Image ref.: 19.jpg]
// Input: head = [1,2,3,4,5], n = 2
// Output: [1,2,3,5]

// Example 2:

// Input: head = [1], n = 1
// Output: []

// Example 3:

// Input: head = [1,2], n = 1
// Output: [1]
 
// Constraints:

// The number of nodes in the list is sz.
// 1 <= sz <= 30
// 0 <= Node.val <= 100
// 1 <= n <= sz 

// Follow up: Could you do this in one pass?

#include <vector>
#include <ostream>

class RemoveNthNodeFromEndOfList {
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto first_ptr = head;
        auto second_ptr = first_ptr;
        while (n > 0 && second_ptr->next != nullptr) {
            second_ptr = second_ptr->next;
            --n;
        }
        if (n > 0) {
            auto next = first_ptr->next;
            delete first_ptr;
            first_ptr = nullptr;
            return next;
        }
        while (second_ptr->next != nullptr) {
            second_ptr = second_ptr->next;
            first_ptr = first_ptr->next;
        }        
        auto to_del = first_ptr->next;
        auto next = to_del->next;
        first_ptr->next = next;
        delete to_del;
        to_del = nullptr;

        return head;
    }

    ListNode* buildList(const std::vector<unsigned short>& data) {
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
            auto next = curr->next;
            delete curr;
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

#endif // REMOVENTHNODE_19_HPP