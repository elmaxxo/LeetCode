/*
 * Given a sorted array of distinct integers and a target value,
 * return the index if the target is found. If not,
 * return the index where it would be if it were inserted in order.
 * 
 * You must write an algorithm with O(log n) runtime complexity.
 * 
 * Example 1:
 * 
 * Input: nums = [1,3,5,6], target = 5
 * Output: 2
 * Example 2:
 * 
 * Input: nums = [1,3,5,6], target = 2
 * Output: 1
 * Example 3:
 * 
 * Input: nums = [1,3,5,6], target = 7
 * Output: 4
 */

#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
        int searchInsert(vector<int>& nums, int target) {
                long long l = 0;
                long long r = nums.size();
                auto m = 0;
                while (l != r) {
                        m = (l + r) / 2;
                        if (nums[m] == target)
                                return m;
                        else if (nums[m] < target)
                                l = m + 1;
                        else
                                r = m;
                }
                return r;
        }
};

int main() {
        vector<int> v = {0, 1, 2, 4, 5};
        
        Solution solution;
        assert(solution.searchInsert(v, 3) == 3);
        assert(solution.searchInsert(v, 2) == 2);
        assert(solution.searchInsert(v, -1) == 0);
        assert(solution.searchInsert(v, 6) == 5);
        return 0;
}