/*
 * Given the root of a binary tree, return its maximum depth.
 * 
 * A binary tree's maximum depth is the number of nodes along
 * the longest path from the root node down to the farthest leaf node. 
 * 
 * Example 1:
 * 
 * Input: root = [3,9,20,null,null,15,7]
 * Output: 3
 * Example 2:
 * 
 * Input: root = [1,null,2]
 * Output: 2
 *  
 * Constraints:
 * 
 * The number of nodes in the tree is in the range [0, 104].
 * -100 <= Node.val <= 100
 */

#include <cassert>
#include <algorithm>

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
        int maxDepthIteration(TreeNode* root, int depth) {
                if (root == nullptr)
                        return depth;
                return max(maxDepthIteration(root->left, depth + 1), maxDepthIteration(root->right, depth + 1)); 
        }

        int maxDepth(TreeNode* root) {
                return maxDepthIteration(root, 0);
        }
};

int main() {
        auto root = new TreeNode(1, new TreeNode(2, new TreeNode(3), new TreeNode(4)), 
                                    new TreeNode(2, new TreeNode(4), new TreeNode(3)));

        Solution solution;
        assert(solution.maxDepth(root) == 3);
        root->left->left->left = new TreeNode(6);
        assert(solution.maxDepth(root) == 4);
        assert(solution.maxDepth(nullptr) == 0);
        return 0;
}