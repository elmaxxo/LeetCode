/*
 * You are given an m x n binary matrix grid. An island is a group of 1's (representing land)
 * connected 4-directionally (horizontal or vertical.) You may assume all four edges of
 * the grid are surrounded by water.
 * 
 * The area of an island is the number of cells with a value 1 in the island.
 * 
 * Return the maximum area of an island in grid. If there is no island, return 0.
 * 
 * Example 1:
 * 
 * Input: grid = [
 *  [0,0,1,0,0,0,0,1,0,0,0,0,0],
 *  [0,0,0,0,0,0,0,1,1,1,0,0,0],
 *  [0,1,1,0,1,0,0,0,0,0,0,0,0],
 *  [0,1,0,0,1,1,0,0,1,0,1,0,0],
 *  [0,1,0,0,1,1,0,0,1,1,1,0,0],
 *  [0,0,0,0,0,0,0,0,0,0,1,0,0],
 *  [0,0,0,0,0,0,0,1,1,1,0,0,0],
 *  [0,0,0,0,0,0,0,1,1,0,0,0,0]
 * ]
 * Output: 6
 * Explanation: The answer is not 11, because the island must be connected 4-directionally.
 * Example 2:
 * 
 * Input: grid = [[0,0,0,0,0,0,0,0]]
 * Output: 0
 *  
 * 
 * Constraints:
 * 
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 50
 * grid[i][j] is either 0 or 1.
 */

#include <cassert>
#include <vector>
#include <utility>

using namespace std;

class Solution {
public:
        int maxAreaOfIsland(vector<vector<int>>& grid) {
                int y_max = grid.size();
                int x_max = grid[0].size();
                int max_area = 0;
                for (int y = 0; y < y_max; ++y) {
                        for (int x = 0; x < x_max; ++x) {
                                if (grid[y][x]) {
                                        int new_area = travel(grid, y, x);
                                        max_area = max(max_area, new_area);
                                }
                        }
                }
                return max_area;
        }

        int travel(vector<vector<int>>& grid, int y, int x) {
                int y_max = grid.size();
                int x_max = grid[0].size();
                if (y < 0 || y_max <= y || x < 0 || x_max <= x || grid[y][x] != 1)
                        return 0;
                
                grid[y][x] = 0;
                return 1 + travel(grid, y, x + 1) + travel(grid, y, x - 1)
                         + travel(grid, y + 1, x) + travel(grid, y - 1, x);
        }
};

int main() {
        vector<vector<int>> grid  = {
                {0, 0, 0, 0, 0, 1},
                {0, 0, 0, 0, 1, 1},
                {0, 0, 1, 0, 1, 1},
                {1, 0, 1, 1, 0, 0},
                {1, 0, 1, 0, 0, 0}
        };

        Solution solution;
        assert(solution.maxAreaOfIsland(grid) == 5);
        return 0;
}