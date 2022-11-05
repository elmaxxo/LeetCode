/*
 * Given an array nums of distinct integers, return all the possible permutations.
 * You can return the answer in any order.
 *
 * Example 1:
 *
 * Input: nums = [1,2,3]
 * Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 * Example 2:
 *
 * Input: nums = [0,1]
 * Output: [[0,1],[1,0]]
 * Example 3:
 *
 * Input: nums = [1]
 * Output: [[1]]
 *
 * Constraints:
 *
 * 1 <= nums.length <= 6
 * -10 <= nums[i] <= 10
 * All the integers of nums are unique.
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    	vector<vector<int>> permute(vector<int>& nums)
	{
		vector<vector<int>> permutationIndexes =
			calculatePermutationIndexes(nums.size());

		vector<vector<int>> permutations(permutationIndexes.size(),
						 vector<int>(nums.size()));

		for (size_t i = 0; i < permutationIndexes.size(); ++i)
			for (size_t j = 0; j < nums.size(); ++j)
				permutations[i][j] =
					nums[permutationIndexes[i][j]];
		return permutations;
    	}

private:
	vector<vector<int>> calculatePermutationIndexes(size_t n)
	{
		vector<int> temporary;
		vector<vector<int>> permutationIndexes;
		backtrack(permutationIndexes, temporary, n);
		return permutationIndexes;
	}

	void backtrack(vector<vector<int>>& indexes, vector<int>& current, size_t n)
	{
		if (current.size() == static_cast<size_t>(n))
			indexes.push_back(current);

		for (size_t i = 0; i < n; ++i) {
			if (find(current.begin(), current.end(), i) == current.end()) {
				current.push_back(i);
				backtrack(indexes, current, n);
				current.pop_back();
			}
		}
	}
};

int main()
{
	Solution solution;

	vector<int> nums = {1, 2, 3};
	auto combs = solution.permute(nums);
	for (const auto& comb : combs) {
		for (auto n : comb)
			cerr << n << ' ';
		cerr << endl;
	}
	return 0;
}
