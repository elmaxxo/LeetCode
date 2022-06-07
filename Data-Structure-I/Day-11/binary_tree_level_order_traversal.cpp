/*
 * Given the root of a binary tree, return the level order traversal of its nodes' values.
 * (i.e., from left to right, level by level).
 *  
 * Example 1:
 * 
 * Input: root = [3,9,20,null,null,15,7]
 * Output: [[3],[9,20],[15,7]]
 * Example 2:
 * 
 * Input: root = [1]
 * Output: [[1]]
 * Example 3:
 * 
 * Input: root = []
 * Output: [] 
 * 
 * Constraints:
 * 
 * The number of nodes in the tree is in the range [0, 2000].
 * -1000 <= Node.val <= 1000
 */

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
        void levelOrderIteration(vector<vector<int>> &vals_on_lvls, TreeNode* node, size_t depth) {
                if (node == nullptr)
                        return;
                if (vals_on_lvls.size() == depth)
                        vals_on_lvls.resize(depth + 1);
                vals_on_lvls[depth].push_back(node->val);
                levelOrderIteration(vals_on_lvls, node->left, depth + 1);
                levelOrderIteration(vals_on_lvls, node->right, depth + 1);
        }

        vector<vector<int>> levelOrder(TreeNode* root) {
                vector<vector<int>> vals;
                levelOrderIteration(vals, root, 0);
                return vals;
        }
};

int main() {
        return 0;
}