/*
 * Given an integer array nums, move all 0's to the end of it while
 * maintaining the relative order of the non-zero elements.
 * 
 * Note that you must do this in-place without making a copy of the array.
 * 
 * Example 1:
 * 
 * Input: nums = [0,1,0,3,12]
 * Output: [1,3,12,0,0]
 * Example 2:
 * 
 * Input: nums = [0]
 * Output: [0]
 *  
 * 
 * Constraints:
 * 
 * 1 <= nums.length <= 104
 * -231 <= nums[i] <= 231 - 1
 *  
 * 
 * Follow up: Could you minimize the total number of operations done?
 */

#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
        void moveZeroes(vector<int>& nums) {
                const int size = nums.size();
                for (int i = size - 1; 0 <= i; --i) {
                        if (nums[i] == 0) {
                                for (int j = i; j+1 < size && nums[j+1] != 0; ++j) {
                                        swap(nums[j], nums[j+1]);
                                }
                        }
                }
        }
};

int main() {
        vector<int> v = {0, 1, 2, 0, 6};

        Solution solution;
        solution.moveZeroes(v);
        assert(v[0] == 1);
        assert(v[1] == 2);
        assert(v[2] == 6);
        assert(v[3] == 0);
        assert(v[4] == 0);
        return 0;
}