/*
 * Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
 *
 * You must implement a solution with a linear runtime complexity and use only constant extra space.
 *
 * Example 1:
 *
 * Input: nums = [2,2,1]
 * Output: 1
 * Example 2:
 *
 * Input: nums = [4,1,2,1,2]
 * Output: 4
 * Example 3:
 *
 * Input: nums = [1]
 * Output: 1
 *
 * Constraints:
 *
 * 1 <= nums.length <= 3 * 104
 * -3 * 104 <= nums[i] <= 3 * 104
 * Each element in the array appears twice except for one element which appears
 * only once.
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	int singleNumber(vector<int>& nums)
	{
		int counter_size = 100000;
		char counter[100000] = {};
		int base_idx = counter_size / 2; // avoid negative numbers
		for (int i = 0, sz = nums.size(); i < sz; ++i) {
			counter[base_idx + nums[i]] += 1;
		}
		for (int i = 0; i < counter_size; ++i) {
			if (counter[i] == 1) {
				return i - base_idx;
			}
		}
		return 0;
	}
};

int main()
{
	vector<int> v = {1, 2, 2, 1, 4, 3, 5, 3, 5};

	Solution solution;
	assert(solution.singleNumber(v) == 4);

	return 0;
}
