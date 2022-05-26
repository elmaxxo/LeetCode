/*
 * Given the head of a singly linked list, return the middle node of the linked list.
 * 
 * If there are two middle nodes, return the second middle node.
 * 
 * Example 1:
 * 
 * Input: head = [1,2,3,4,5]
 * Output: [3,4,5]
 * Explanation: The middle node of the list is node 3.
 * Example 2:
 * 
 * Input: head = [1,2,3,4,5,6]
 * Output: [4,5,6]
 * Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.
 */

/**
 * Definition for singly-linked list.
 */

#include <cassert>

struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
        ListNode* middleNode(ListNode* head) {
                ListNode* fast = head;
                ListNode* slow = head;
                while (fast && fast->next) {
                        fast = fast->next->next;
                        slow = slow->next;
                }
                return slow;
        }
};

int main() {
        ListNode alone;
        ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4))));

        Solution solution;
        assert(solution.middleNode(&alone) == &alone);
        assert(solution.middleNode(head)->val == 3);
        return 0;
}