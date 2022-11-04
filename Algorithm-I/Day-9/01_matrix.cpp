/*
 * Given an m x n binary matrix mat, return the distance of the nearest 0 for
 * each cell.
 *
 * The distance between two adjacent cells is 1.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
 * Output: [[0,0,0],[0,1,0],[0,0,0]]
 * Example 2:
 *
 *
 * Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
 * Output: [[0,0,0],[0,1,0],[1,2,1]]
 *
 *
 * Constraints:
 *
 * m == mat.length
 * n == mat[i].length
 * 1 <= m, n <= 104
 * 1 <= m * n <= 104
 * mat[i][j] is either 0 or 1.
 * There is at least one 0 in mat.
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	vector<vector<int>> updateMatrix(vector<vector<int>>& mat)
	{
		int rows = mat.size();
		int cols = mat[0].size();
		vector<vector<int>> distances(rows, vector<int>(cols, INT_MAX - 1));
		for (int r = 0; r < rows; ++r) {
			for (int c = 0; c < cols; ++c) {
				if (mat[r][c] == 0) {
					distances[r][c] = 0;
				} else {
					if (r != 0) {
						distances[r][c] = min(distances[r][c], distances[r-1][c] + 1);
					}
					if (c != 0) {
						distances[r][c] = min(distances[r][c], distances[r][c-1] + 1);
					}
				}
			}
		}

		for (int r = rows - 1; r >= 0; --r) {
			for (int c = cols - 1; c >= 0; --c) {
				if (r != rows - 1) {
					distances[r][c] = min(distances[r][c], distances[r+1][c] + 1);
				}
				if (c != cols - 1) {
					distances[r][c] = min(distances[r][c], distances[r][c+1] + 1);
				}
			}
		}

		return distances;
	}
};

int main()
{
	assert(false && "not tested")
	return 0;
}
