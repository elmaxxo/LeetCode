/*
 * Given an array of integers nums and an integer target, return indices
 * of the two numbers such that they add up to target.
 * 
 * You may assume that each input would have exactly one solution,
 * and you may not use the same element twice.
 * 
 * You can return the answer in any order.
 * 
 * Example 1:
 * 
 * Input: nums = [2,7,11,15], target = 9
 * Output: [0,1]
 * Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
 * Example 2:
 * 
 * Input: nums = [3,2,4], target = 6
 * Output: [1,2]
 * Example 3:
 * 
 * Input: nums = [3,3], target = 6
 * Output: [0,1]
 * 
 * Constraints:
 * 
 * 2 <= nums.length <= 104
 * -109 <= nums[i] <= 109
 * -109 <= target <= 109
 * Only one valid answer exists.
 */

#include <cassert>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
        vector<int> twoSum(vector<int>& nums, int target) {
                vector<int> nums_copy(nums.size());
                copy(nums.begin(), nums.end(), nums_copy.begin());
                sort(nums_copy.begin(), nums_copy.end());

                int vals[2] = {};
                for (auto it = nums_copy.begin(), it_end = nums_copy.end(); it != it_end; ++it) {
                        if (binary_search(it + 1, it_end, target - *it)) {
                                vals[0] = *it;
                                vals[1] = target - *it;
                                break;
                        }
                }
                int idx1 = find_first_of(nums.begin(), nums.end(), vals, vals + 1) - nums.begin();
                int idx2 = nums.size() - 1 -
                        (find_first_of(nums.rbegin(), nums.rend(), vals + 1, vals + 2) - nums.rbegin());
                return {idx1, idx2};
    }
};

int main() {
        vector<int> v1 = {1, 2, 3, 4, -5, 6, -7, 8, 9};

        Solution solution;
        auto res1 = solution.twoSum(v1, 3); 
        auto res2 = solution.twoSum(v1, -1);
        auto res3 = solution.twoSum(v1, 17);
        assert(v1[res1[0]] + v1[res1[1]] == 3);
        assert(v1[res2[0]] + v1[res2[1]] == -1);
        assert(v1[res3[0]] + v1[res3[1]] == 17);
        return 0;
}