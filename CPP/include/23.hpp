#ifndef MERGEKSORTEDLIST_23_HPP
#define MERGEKSORTEDLIST_23_HPP

// 23. Merge k Sorted Lists

// Hard

// You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
// Merge all the linked-lists into one sorted linked-list and return it.

// Example 1:

// Input: lists = [[1,4,5],[1,3,4],[2,6]]
// Output: [1,1,2,3,4,4,5,6]
// Explanation: The linked-lists are:
// [
//   1->4->5,
//   1->3->4,
//   2->6
// ]
// merging them into one sorted linked list:
// 1->1->2->3->4->4->5->6

// Example 2:

// Input: lists = []
// Output: []

// Example 3:

// Input: lists = [[]]
// Output: []

// Constraints:

// k == lists.length
// 0 <= k <= 10^4
// 0 <= lists[i].length <= 500
// -10^4 <= lists[i][j] <= 10^4
// lists[i] is sorted in ascending order.
// The sum of lists[i].length will not exceed 10^4.

#include <vector>
#include <iostream>

class MergeKSortedList {
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
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        auto i = 0;
        auto j = -1;
        while (i < lists.size()) {
            if (j < 0) {
                j = i;
                ++i;
            } else {
                lists[i] = mergeTwoLists(lists[j], lists[i]);
                j = -1;
            }
        }
        return (i > 0) ? lists.at(lists.size() - 1) : nullptr;
    }

    std::vector<ListNode*> buildLists(const std::vector<std::vector<int>>& dataList) {
        std::vector<ListNode*> list_nodes;
        list_nodes.reserve(dataList.size());
        for (const auto& data : dataList) {
            auto list_node = buildList(data);
            list_nodes.push_back(list_node);
        }
        return list_nodes;
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

    void printNodeLists(const std::vector<ListNode*>& list_nodes) {
        std::cout << '[';
        for (auto i = 0; i < list_nodes.size(); ++i) {
            std::cout << list_nodes.at(i);
            if (i < list_nodes.size() - 1) {
                std::cout << ',';
            }
        }
        std::cout << "]\n";        
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

private:
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
};

#endif // MERGEKSORTEDLIST_23_HPP