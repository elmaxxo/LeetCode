/*
 *  You are given an m x n grid where each cell can have one of three values:
 *
 * 0 representing an empty cell,
 * 1 representing a fresh orange, or
 * 2 representing a rotten orange.
 * Every minute, any fresh orange that is 4-directionally adjacent to a rotten
 * orange becomes rotten.
 *
 * Return the minimum number of minutes that must elapse until no cell has a
 * fresh orange. If this is impossible, return -1.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
 * Output: 4
 * Example 2:
 *
 * Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
 * Output: -1
 * Explanation: The orange in the bottom left corner (row 2, column 0) is never
 * rotten, because rotting only happens 4-directionally.
 * Example 3:
 *
 * Input: grid = [[0,2]]
 * Output: 0
 * Explanation: Since there are already no fresh oranges at minute 0, the
 * answer is just 0.
 */

#include <bits/stdc++.h>

using namespace std;

enum Orange {
	EMPTY = 0,
	FRESH = 1,
	ROTTEN = 2,
	ROTTEN_RECENTLY = 3,
};


class Solution {
public:
    	int orangesRotting(vector<vector<int>>& grid)
	{
		size_t minutes = 0;
		while (rot(grid))
			minutes += 1;

		for (size_t i = 0, isz = grid.size(); i < isz; ++i) {
			for (size_t j = 0, jsz = grid[0].size(); j < jsz; ++j) {
				if (grid[i][j] == Orange::FRESH)
					return -1;
			}
		}

		return minutes;
	}

private:
	void spreadRotting(vector<vector<int>>& grid, size_t i, size_t isz,
						      size_t j, size_t jsz)
	{
		if (i + 1 < isz && grid[i+1][j] == Orange::FRESH)
			grid[i+1][j] = Orange::ROTTEN_RECENTLY;
		if (i >= 1 && grid[i-1][j] == Orange::FRESH)
			grid[i-1][j] = Orange::ROTTEN_RECENTLY;
		if (j + 1 < jsz && grid[i][j+1] == Orange::FRESH)
			grid[i][j+1] = Orange::ROTTEN_RECENTLY;
		if (j >= 1 && grid[i][j-1] == Orange::FRESH)
			grid[i][j-1] = Orange::ROTTEN_RECENTLY;
	}

	bool rot(vector<vector<int>>& grid)
	{
		for (size_t i = 0, isz = grid.size(); i < isz; ++i) {
			for (size_t j = 0, jsz = grid[0].size(); j < jsz; ++j) {
				if (grid[i][j] == Orange::ROTTEN) {
					spreadRotting(grid, i, isz, j, jsz);
				}
			}
		}

		bool spread = false;
		for (size_t i = 0, isz = grid.size(); i < isz; ++i) {
			for (size_t j = 0, jsz = grid[0].size(); j < jsz; ++j) {
				if (grid[i][j] == Orange::ROTTEN_RECENTLY) {
					grid[i][j] = Orange::ROTTEN;
					spread = true;
				}
			}
		}
		return spread;
	}
};

int main()
{
	vector<vector<int>> grid1 = {
		{Orange::ROTTEN, Orange::FRESH},
		{Orange::FRESH,  Orange::FRESH}
	};

	vector<vector<int>> grid2 = {
		{Orange::ROTTEN, Orange::EMPTY},
		{Orange::EMPTY,  Orange::EMPTY}
	};

	Solution solution;
	assert(solution.orangesRotting(grid1) == 2);
	assert(solution.orangesRotting(grid2) == 0);
	return 0;
}
