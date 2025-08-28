#ifndef ROTATELIST_HPP
#define ROTATELIST_HPP

// 61. Rotate List

// Medium

// Given the head of a linked list, rotate the list to the right by k places.

// Example 1:

// Input: head = [1,2,3,4,5], k = 2
// Output: [4,5,1,2,3] (ref. image: 61_01.jpg)

// Example 2:

// Input: head = [0,1,2], k = 4
// Output: [2,0,1] (ref. image: 61_02.jpg)
 
// Constraints:

// The number of nodes in the list is in the range [0, 500].
// -100 <= Node.val <= 100
// 0 <= k <= 2 * 10^9

#include <iostream>

class RotateList {
public:
    RotateList(): start(nullptr) {}
    ~RotateList() {
        deleteList();
    }

    /**
    * Definition for singly-linked list.
    **/
    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

    void appendNode(const int val) {
        if (start == nullptr) {
            start = new ListNode(val);
        } else {
            auto curr = start;
            while (curr->next != nullptr) {
                curr = curr->next;
            }
            curr->next = new ListNode(val);
        }
    }

    void prependNode(const int val) {
        auto node = new ListNode(val, start);
        start = node;
    }

    ListNode* getList() {
        return start;
    }

    void setList(ListNode* node) {
        start = node;
    }    

    void deleteList() {
        if (start != nullptr) {
            auto curr_node = start;
            auto next_node = curr_node->next;
            while (curr_node != nullptr) {
                const auto val = curr_node->val;
                delete curr_node;
                std::cout << "Node: " << val << " deleted\n";
                curr_node = next_node;
                if (next_node != nullptr) {
                    next_node = next_node->next;
                }
            }
            start = nullptr;
        }
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if (k == 0 || head == nullptr) {
            return head;
        }
        auto first = head;
        auto second = head;
        long d = k;
        while (d > 0 && second->next != nullptr) {
            second = second->next;
            --d;
        }
        if (d == k) {
            // only a single node
            return head;
        }
        if (d > 0) {
            d = k - d + 1;
            d = k % d;
            second = head;
            while (d > 0 && second->next != nullptr) {
                second = second->next;
                --d;
            }
        }
        while (second->next != nullptr) {
            second = second->next;
            first = first->next;
        }
        second->next = head;
        head = first->next;
        first->next = nullptr;

        return head;
    }

private:
    ListNode *start;
};

std::ostream& operator<<(std::ostream& os, const RotateList::ListNode* node) {
    os << '[';
    for (auto curr = node; curr != nullptr; curr = curr->next) {
        os << curr->val;
        if (curr->next != nullptr) {
            os << ", ";
        }
    }
    os << "]\n";
    return os;
}

#endif // ROTATELIST_HPP