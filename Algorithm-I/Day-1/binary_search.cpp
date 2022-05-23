/*
 * Given an array of integers nums which is sorted in ascending order,
 * and an integer target, write a function to search target in nums.
 * If target exists, then return its index. Otherwise, return -1.
 * 
 * You must write an algorithm with O(log n) runtime complexity.
 * 
 *  
 * 
 * Example 1:
 * 
 * Input: nums = [-1,0,3,5,9,12], target = 9
 * Output: 4
 * Explanation: 9 exists in nums and its index is 4
 * Example 2:
 * 
 * Input: nums = [-1,0,3,5,9,12], target = 2
 * Output: -1
 * Explanation: 2 does not exist in nums so return -1
 *  
 * 
 * Constraints:
 * 
 * 1 <= nums.length <= 104
 * -104 < nums[i], target < 104
 * All the integers in nums are unique.
 * nums is sorted in ascending order.
 */

#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
        int search(vector<int>& nums, int target) {
                int l = 0;
                int r = nums.size();
                while (l != r) {
                        int m = (r + l) / 2;
                        if (nums[m] == target)
                                return m;
                        if (nums[m] < target)
                                l = m + 1;
                        else 
                                r = m;
                }
                return -1;
    }
};

int main() {
        vector<int> v1 = {0, 1, 2, 3, 4, 5, 6};
        
        Solution solution;
        assert(solution.search(v1, -1) == -1);
        assert(solution.search(v1, 0) == 0);
        assert(solution.search(v1, 1) == 1);
        assert(solution.search(v1, 2) == 2);
        assert(solution.search(v1, 3) == 3);
        assert(solution.search(v1, 4) == 4);
        assert(solution.search(v1, 5) == 5);
        assert(solution.search(v1, 6) == 6);
        assert(solution.search(v1, 7) == -1);
}