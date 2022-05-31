/*
 * Given the head of a singly linked list, reverse the list,
 * and return the reversed list.
 * 
 * Example 1:
 * 
 * Input: head = [1,2,3,4,5]
 * Output: [5,4,3,2,1]
 * Example 2:
 * 
 * Input: head = [1,2]
 * Output: [2,1]
 * Example 3:
 * 
 * Input: head = []
 * Output: []
 *  
 * Constraints:
 * 
 * The number of nodes in the list is the range [0, 5000].
 * -5000 <= Node.val <= 5000
 *  
 * Follow up: A linked list can be reversed either iteratively or
 * recursively. Could you implement both?
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
        ListNode* reverseList(ListNode* head) {
                ListNode* prev = nullptr;
                ListNode* curr = head;
                ListNode* next = nullptr;
                while (curr) {
                        next = curr->next;
                        curr->next = prev;
                        prev = curr;
                        curr = next;
                }
        
                return prev;
    }
};

int main() {
        ListNode *list = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4))));

        Solution solution;
        auto reversed = solution.reverseList(list);
        assert(reversed != nullptr);
        assert(reversed->val == 4);
        assert(reversed->next->val == 3);
        assert(reversed->next->next->val == 2);
        assert(reversed->next->next->next->val == 1);
        assert(reversed->next->next->next->next == nullptr);
        return 0;
}