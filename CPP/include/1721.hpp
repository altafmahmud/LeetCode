#ifndef SWAPNODESLINKEDLIST_1721_HPP
#define SWAPNODESLINKEDLIST_1721_HPP

// 1721. Swapping Nodes in a Linked List

// Medium

// You are given the head of a linked list, and an integer k.
// Return the head of the linked list after swapping the values of the kth node from the beginning and the kth node from the end (the list is 1-indexed).

// Example 1:
// [Image ref.: 1721.jpg]
// Input: head = [1,2,3,4,5], k = 2
// Output: [1,4,3,2,5]

// Example 2:

// Input: head = [7,9,6,6,7,8,3,0,9,5], k = 5
// Output: [7,9,6,6,8,7,3,0,9,5]

// Constraints:

// The number of nodes in the list is n.
// 1 <= k <= n <= 10^5
// 0 <= Node.val <= 100

#include <vector>
#include <ostream>

class SwapNodesInLinkedList {
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
    ListNode* swapNodes(ListNode* head, int k) {
        auto first_ptr = head;
        auto second_ptr = first_ptr;
        while (k > 1 && second_ptr->next != nullptr) {
            second_ptr = second_ptr->next;
            --k;
        }
        if (k > 1) {
            return head;
        }
        auto first_node = second_ptr;
        while (second_ptr->next != nullptr) {
            second_ptr = second_ptr->next;
            first_ptr = first_ptr->next;
        }
        auto second_node = first_ptr;
        if (first_node != second_node) {
            const auto temp = first_node->val;
            first_node->val = second_node->val;
            second_node->val = temp;            
        }
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

#endif // SWAPNODESLINKEDLIST_1721_HPP