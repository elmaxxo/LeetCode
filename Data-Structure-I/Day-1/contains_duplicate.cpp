/*
 * Given an integer array nums, return true if any value appears at least
 * twice in the array, and return false if every element is distinct.
 * 
 * Example 1:
 * 
 * Input: nums = [1,2,3,1]
 * Output: true
 * Example 2:
 * 
 * Input: nums = [1,2,3,4]
 * Output: false
 * Example 3:
 * 
 * Input: nums = [1,1,1,3,3,4,3,2,4,2]
 * Output: true
 *  
 * Constraints:
 * 
 * 1 <= nums.length <= 105
 * -109 <= nums[i] <= 109
 */

#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (size_t i = 1, sz = nums.size(); i < sz; ++i)
                if (nums[i-1] == nums[i])
                        return true;
        return false;
    }
};

int main() {
        vector<int> empty = {};
        vector<int> with_duplicates = {1, 1, 3, 5};
        vector<int> without_duplicates = {1, 3, 5};
        Solution solution;
        assert(solution.containsDuplicate(empty) == false);
        assert(solution.containsDuplicate(with_duplicates) == true);
        assert(solution.containsDuplicate(without_duplicates) == false);
        return 0;
}