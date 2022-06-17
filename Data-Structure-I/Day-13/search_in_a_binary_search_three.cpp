/*
 * You are given the root of a binary search tree (BST) and an integer val.
 * 
 * Find the node in the BST that the node's value equals val and return the
 * subtree rooted with that node. If such a node does not exist, return null.
 * 
 * Example 1:
 * 
 * Input: root = [4,2,7,1,3], val = 2
 * Output: [2,1,3]
 * Example 2:
 * 
 * Input: root = [4,2,7,1,3], val = 5
 * Output: []
 * 
 * Constraints:
 * 
 * The number of nodes in the tree is in the range [1, 5000].
 * 1 <= Node.val <= 107
 * root is a binary search tree.
 * 1 <= val <= 107
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
public:
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

};

int main() {
        TreeNode *root = new TreeNode(2, new TreeNode(1), new TreeNode(3));

        Solution solution;
        assert(solution.searchBST(root, 2) == root);
        assert(solution.searchBST(root, 1) == root->left);
        assert(solution.searchBST(root, 3) == root->right);
        assert(solution.searchBST(root, 0) == nullptr);
        assert(solution.searchBST(root, 4) == nullptr);
        return 0;
}