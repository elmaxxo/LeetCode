/*
 * Given an integer array nums, find the contiguous subarray 
 * (containing at least one number) which has the largest sum and return its sum.
 * 
 * A subarray is a contiguous part of an array.
 * 
 * Example 1:
 * 
 * Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
 * Output: 6
 * Explanation: [4,-1,2,1] has the largest sum = 6.
 * Example 2:
 * 
 * Input: nums = [1]
 * Output: 1
 * Example 3:
 * 
 * Input: nums = [5,4,-1,7,8]
 * Output: 23
 *  
 * Constraints:
 * 
 * 1 <= nums.length <= 105
 * -104 <= nums[i] <= 104
 */

#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0)
                return 0;
        int max_sum = nums[0];
        int cur_sum = 0;
        for (int i = 0, sz = nums.size(); i < sz; ++i) {
                cur_sum += nums[i];
                if (max_sum < cur_sum)
                        max_sum = cur_sum;
                if (cur_sum < 0)
                        cur_sum = 0;
        }
        return max_sum;
    }
};

int main() {
        vector<int> v1 = {1, 2, 3, 4, 5};
        vector<int> v2 = {1, 2, 3, -4, 5};
        vector<int> v3 = {-1, 2, 3, -4, 5};
        vector<int> v4 = {-1, -2, -3, -4, -5};
        vector<int> v5 = {-1};
        vector<int> v6 = {-2, -1};

        Solution solution;
        assert(solution.maxSubArray(v1) == 15);
        assert(solution.maxSubArray(v2) == 7);
        assert(solution.maxSubArray(v3) == 6);
        assert(solution.maxSubArray(v4) == -1);
        assert(solution.maxSubArray(v5) == -1);
        assert(solution.maxSubArray(v6) == -1);
        return 0;
}