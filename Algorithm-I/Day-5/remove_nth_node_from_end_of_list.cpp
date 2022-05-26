/*
 * Given the head of a linked list, remove the nth node from the end of the list and return its head.
 * 
 * Example 1:
 * 
 * Input: head = [1,2,3,4,5], n = 2
 * Output: [1,2,3,5]
 * Example 2:
 * 
 * Input: head = [1], n = 1
 * Output: []
 * Example 3:
 * 
 * Input: head = [1,2], n = 1
 * Output: [1]
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
        ListNode *removeNthFromEnd(ListNode *head, int n) {
                ListNode ghost;
                ghost.next = head;
                ListNode *fast = &ghost;
                ListNode *slow = &ghost;
                for (int i = 0; i < n; ++i)
                        fast = fast->next;

                while (fast->next) {
                        fast = fast->next;
                        slow = slow->next;
                }

                slow->next = slow->next->next;
                return ghost.next;
        }
};

int main() {
        ListNode *node4 = new ListNode(1);        (void)node4;
        ListNode *node3 = new ListNode(2, node4); (void)node3;
        ListNode *node2 = new ListNode(3, node3); (void)node2;
        ListNode *node1 = new ListNode(4, node2); (void)node1;

        Solution solution;
        ListNode *head = solution.removeNthFromEnd(node1, 1);
        assert(node3->next == nullptr);
        assert(head == node1);
        head = solution.removeNthFromEnd(node1, 3);
        assert(head == node2);
        return 0;
}