/*
 * Given the root of a Binary Search Tree and a target number k,
 * return true if there exist two elements in the BST such that
 * their sum is equal to the given target.
 * 
 * Example 1:
 * 
 * Input: root = [5,3,6,2,4,null,7], k = 9
 * Output: true
 * Example 2:
 * 
 * Input: root = [5,3,6,2,4,null,7], k = 28
 * Output: false
 * 
 * Constraints:
 * 
 * The number of nodes in the tree is in the range [1, 104].
 * -104 <= Node.val <= 104
 * root is guaranteed to be a valid binary search tree.
 * -105 <= k <= 105
 */

#include <cassert>

struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
        TreeNode* searchBST(TreeNode* root, int val) {
                if (root) {
                        if (root->val == val)
                                return root;
                        if (root->val < val)
                               return searchBST(root->right, val);
                        else
                               return searchBST(root->left, val);
                }
                return nullptr;
        }

public:
        bool findTarget(TreeNode* node, int k, TreeNode* root) {
                if (node == nullptr) {
                        return false;
                }
                auto found = searchBST(root, k - node->val);
                if (found != nullptr && found != node) {
                        return true;
                }
                return findTarget(node->left, k, root) || findTarget(node->right, k, root);
        }

        bool findTarget(TreeNode* node, int k) {
                return findTarget(node, k, node);
        }
};

int main() {
        TreeNode *root = new TreeNode(2, new TreeNode(1), new TreeNode(3));

        Solution solution;
        assert(solution.findTarget(root, 3));
        assert(solution.findTarget(root, 5));
        assert(solution.findTarget(root, 4));
        return 0;
}