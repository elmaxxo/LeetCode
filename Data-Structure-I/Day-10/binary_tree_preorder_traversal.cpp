/*
 * Given the root of a binary tree, return the preorder traversal of its nodes' values.
 * 
 * 
 * Example 1:
 * 
 * Input: root = [1,null,2,3]
 * Output: [1,2,3]
 * Example 2:
 * 
 * Input: root = []
 * Output: []
 * Example 3:
 * 
 * Input: root = [1]
 * Output: [1]
 * 
 * Constraints:
 * 
 * The number of nodes in the tree is in the range [0, 100].
 * -100 <= Node.val <= 100
 */

#include <cassert>
#include <vector>

using namespace std;

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
        vector<int> preorderTraversal(TreeNode* root) {
                if (root) {
                        res.push_back(root->val);
                        preorderTraversalAction(root->left);
                        preorderTraversalAction(root->right);
                }
                return res;
        }

        void preorderTraversalAction(TreeNode *node) {
                if (node) {
                        res.push_back(node->val);
                        preorderTraversalAction(node->left);
                        preorderTraversalAction(node->right);
                }
        }

private:
        vector<int> res;
};

int main() {
        assert(false && "MAKE TESTS");
        return 0;
}