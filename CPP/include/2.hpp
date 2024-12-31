// 2. Add Two Numbers

// Medium

// You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit.
// Add the two numbers and return the sum as a linked list.

// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

// Example 1:
// 2 --> 4 --> 3
// 5 --> 6 --> 4
// -------------
// 7 --> 0 --> 8

// Input: l1 = [2,4,3], l2 = [5,6,4]
// Output: [7,0,8]
// Explanation: 342 + 465 = 807.

// Example 2:

// Input: l1 = [0], l2 = [0]
// Output: [0]
// Example 3:

// Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
// Output: [8,9,9,9,0,0,0,1]

// Constraints:

// The number of nodes in each linked list is in the range [1, 100].
// 0 <= Node.val <= 9
// It is guaranteed that the list represents a number that does not have leading zeros.

#pragma once

#include <iostream>
#include <vector>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class AddTwoNum
{
public:
    // only this method is the actual solution
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        auto sum = 0, carry = 0;
        ListNode *res_head = nullptr;
        auto res_current = res_head;
        while (l1 != nullptr | l2 != nullptr)
        {
            sum = 0;
            if (l1 != nullptr)
            {
                sum += l1->val;
            }
            if (l2 != nullptr)
            {
                sum += l2->val;
            }
            sum += carry;
            if (sum > 9)
            {
                carry = 1;
                sum %= 10;
            }
            else
            {
                carry = 0;
            }
            auto p_node = new ListNode(sum);
            if (res_head == nullptr)
            {
                res_head = p_node;
                res_current = res_head;
            }
            else
            {
                res_current->next = p_node;
                res_current = res_current->next;
            }
            if (l1 != nullptr)
            {
                l1 = l1->next;
            }
            if (l2 != nullptr)
            {
                l2 = l2->next;
            }
        }
        if (carry > 0)
        {
            auto p_node = new ListNode(carry);
            if (res_head == nullptr)
            {
                res_head = p_node;
            }
            else
            {
                res_current->next = p_node;
            }
        }
        return res_head;
    }

    ListNode *buildList(const std::vector<int> &vec)
    {
        ListNode *head = nullptr;
        auto current = head;
        for (const auto num : vec)
        {
            auto p_node = new ListNode(num);
            if (head == nullptr)
            {
                head = p_node;
                current = head;
            }
            else
            {
                current->next = p_node;
                current = current->next;
            }
        }
        return head;
    }

    void printList(const ListNode *head)
    {
        auto current = head;
        std::cout << '[';
        while (current != nullptr)
        {
            std::cout << current->val;
            if (current->next != nullptr)
            {
                std::cout << ',';
            }
            current = current->next;
        }
        std::cout << "]\n";
    }

    void clearList(ListNode *head)
    {
        unsigned count = 0;
        auto current = head;
        while (current != nullptr)
        {
            auto next = current->next;
            delete current;
            current = next;
            ++count;
        }
        head = nullptr;
        std::cout << count << " nodes cleared\n";
    }
};