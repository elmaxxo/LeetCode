/*
 * Given the head of a linked list and an integer val, remove all the nodes of
 * the linked list that has Node.val == val, and return the new head.
 * 
 * Example 1:
 * 
 * Input: head = [1,2,6,3,4,5,6], val = 6
 * Output: [1,2,3,4,5]
 * Example 2:
 * 
 * Input: head = [], val = 1
 * Output: []
 * Example 3:
 * 
 * Input: head = [7,7,7,7], val = 7
 * Output: []
 *  
 * Constraints:
 * 
 * The number of nodes in the list is in the range [0, 104].
 * 1 <= Node.val <= 50
 * 0 <= val <= 50
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
        ListNode* removeElements(ListNode* head, int val) {
                ListNode ghost(0, head);
                
                ListNode* curr = &ghost;
                while (curr && curr->next) {
                        while (curr->next && curr->next->val == val) {
                                curr->next = curr->next->next;
                        }
                        curr = curr->next;
                }
                return ghost.next;
        }
};

int main() {
        ListNode* list = new ListNode(1, new ListNode(2, new ListNode(2, new ListNode(3))));
        
        Solution solution;
        list = solution.removeElements(list, 2);
        assert(list->val == 1 && list->next->val == 3);
        list = solution.removeElements(list, 3);
        assert(list->val == 1 && list->next == nullptr);
        list = solution.removeElements(list, 1);
        assert(list == nullptr);
        return 0;
}