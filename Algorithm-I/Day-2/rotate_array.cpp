/*
 * Given an array, rotate the array to the right by k steps, where k is non-negative.
 *
 * Example 1:
 * 
 * Input: nums = [1,2,3,4,5,6,7], k = 3
 * Output: [5,6,7,1,2,3,4]
 * Explanation:
 * rotate 1 steps to the right: [7,1,2,3,4,5,6]
 * rotate 2 steps to the right: [6,7,1,2,3,4,5]
 * rotate 3 steps to the right: [5,6,7,1,2,3,4]
 * Example 2:
 * 
 * Input: nums = [-1,-100,3,99], k = 2
 * Output: [3,99,-1,-100]
 * Explanation: 
 * rotate 1 steps to the right: [99,-1,-100,3]
 * rotate 2 steps to the right: [3,99,-1,-100]
 *  
 * 
 * Constraints:
 * 
 * 1 <= nums.length <= 105
 * -231 <= nums[i] <= 231 - 1
 * 0 <= k <= 105
 *  
 * 
 * Follow up:
 * 
 * Try to come up with as many solutions as you can.
 * There are at least three different ways to solve this problem.
 * Could you do it in-place with O(1) extra space?
 */

#include <cassert>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
        void rotate(vector<int>& nums, int k) {
                k = k % nums.size();
                /* 1, 2, 3, 4 -> 2 = 3, 4, 1, 2 */
                reverse(begin(nums), end(nums));       /* 4, 3, 2, 1 */ 
                reverse(begin(nums) + k, end(nums));   /* 4, 3, 1, 2 */ 
                reverse(begin(nums), begin(nums) + k); /* 3, 4, 2, 1 */
        }
};

int main() {
        vector<int> v = {1, 2, 3, 4};
        
        Solution solution;
        solution.rotate(v, 2);
        assert(v[0] == 3);
        assert(v[1] == 4);
        assert(v[2] == 1);
        assert(v[3] == 2);

        vector<int> v2 = {-1};
        solution.rotate(v2, 4);
        assert(v2[0] == -1);
}