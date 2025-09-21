#ifndef REVNODESK_25_HPP
#define REVNODESK_25_HPP

// 25. Reverse Nodes in k-Group

// Hard

// Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

// k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

// You may not alter the values in the list's nodes, only nodes themselves may be changed.

// Example 1:
// [Image reference: 25_1.jpg]
// Input: head = [1,2,3,4,5], k = 2
// Output: [2,1,4,3,5]

// Example 2:
// [Image reference: 25_2.jpg]
// Input: head = [1,2,3,4,5], k = 3
// Output: [3,2,1,4,5]
 
// Constraints:

// The number of nodes in the list is n.
// 1 <= k <= n <= 5000
// 0 <= Node.val <= 1000
 
// Follow-up: Can you solve the problem in O(1) extra memory space?

#include <vector>
#include <utility>
#include <ostream>

namespace ReverseNodesInKGroup {
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

std::ostream &operator<<(std::ostream &os, ListNode *head) {
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

class RevNodesKGrp {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* prev = nullptr;
        if (k == 1) {
            return head;
        }
        ListNode* start = nullptr;
        auto from = head;
        auto j = k;
        auto to = kthNode(from, j);
        while (j == 1) {
            auto node_pair = reverseList(prev, from, to);
            from = node_pair.first;
            to = node_pair.second;
            if (start == nullptr) {
                start = from;
            }
            if (to->next == nullptr) {
                break;
            }
            prev = to;
            from = to->next;
            j = k;
            to = kthNode(from, j);
        }
        return (start != nullptr) ? start : head;
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

private:
    ListNode* kthNode(ListNode* from, int& k) {
        auto node = from;
        while (node->next != nullptr && k > 1) {
            node = node->next;
            --k;
        }
        return node;
    }

    std::pair<ListNode*, ListNode*> reverseList(ListNode* prev, ListNode* from, ListNode* to) {
        auto end = to->next;
        auto node01 = from;
        auto node02 = from->next;
        while (node02 != end) {
            auto node03 = node02->next;
            node02->next = node01;
            node01 = node02;
            node02 = node03;
        }
        to = from;
        from = node01;
        to->next = end;
        if (prev != nullptr) {
            prev->next = from;
        }
        return std::make_pair(from, to);
    }
};

} // ReverseNodesInKGroup

#endif // REVNODESK_25_HPP