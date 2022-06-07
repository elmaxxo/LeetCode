/*
 * Given the root of a binary tree, check whether it is
 * a mirror of itself (i.e., symmetric around its center).
 *  
 * Example 1:
 * 
 * Input: root = [1,2,2,3,4,4,3]
 * Output: true
 * Example 2:
 * 
 * Input: root = [1,2,2,null,3,null,3]
 * Output: false
 * 
 * Constraints:
 * 
 * The number of nodes in the tree is in the range [1, 1000].
 * -100 <= Node.val <= 100
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
        bool isSymmetricIteration(TreeNode* l, TreeNode* r) {
                if (r == nullptr && l == nullptr) {
                        return true;
                } else if (r == nullptr || l == nullptr) {
                        return false;
                } else if (l->val != r->val) {
                        return false;
                }

                return isSymmetricIteration(l->left, r->right) && isSymmetricIteration(l->right, r->left);
        }

        bool isSymmetric(TreeNode* root) {
                return root ? isSymmetricIteration(root->left, root->right)
                            : true;
        }
};

int main() {
        auto root = new TreeNode(1, new TreeNode(2, new TreeNode(3), new TreeNode(4)), 
                                    new TreeNode(2, new TreeNode(4), new TreeNode(3)));

        Solution solution;
        assert(solution.isSymmetric(root) == true);
        root->left->val = root->left->val + 1;
        assert(solution.isSymmetric(root) == false);
        return 0;
}