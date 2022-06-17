/*
 * Given a triangle array, return the minimum path sum from top to bottom.
 * 
 * For each step, you may move to an adjacent number of the row below.
 * More formally, if you are on index i on the current row, you may move
 * to either index i or index i + 1 on the next row.
 * 
 * Example 1:
 * 
 * Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
 * Output: 11
 * Explanation: The triangle looks like:
 *    2
 *   3 4
 *  6 5 7
 * 4 1 8 3
 * The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
 * Example 2:
 * 
 * Input: triangle = [[-10]]
 * Output: -10
 * 
 * Constraints:
 * 
 * 1 <= triangle.length <= 200
 * triangle[0].length == 1
 * triangle[i].length == triangle[i - 1].length + 1
 * -104 <= triangle[i][j] <= 104
 * 
 * Follow up: Could you do this using only O(n) extra space, where n is the total number of rows in the triangle?
 */

#include <cassert>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
        int minimumTotal(vector<vector<int>>& triangle) {
                const size_t sz = triangle.size();
                int dp[sz][sz + 1];
                dp[0][0] = triangle[0][0];
                for (size_t i = 1; i < sz; ++i) {
                        for (size_t j = 0; j <= i; ++j) {
                                if (j == 0) {
                                        dp[i][j] = triangle[i][j] + dp[i-1][j];
                                } else if (j == i) {
                                        dp[i][j] = triangle[i][j] + dp[i-1][j-1];
                                } else {
                                        dp[i][j] = triangle[i][j] + min(dp[i-1][j-1], dp[i-1][j]);
                                }
                        }
                }

                return *min_element(&dp[sz - 1][0], &dp[sz - 1][sz]);
        }
};

int main() {
        vector<vector<int>> triangle = {
                {2},
                {3, 4},
                {6, 5, 7},
        };

        Solution solution;
        assert(solution.minimumTotal(triangle) == 10);
        triangle.push_back({4,1,8,3});
        assert(solution.minimumTotal(triangle) == 11);
        triangle.push_back({4,7,8,3,-10});
        assert(solution.minimumTotal(triangle) == 6);
        return 0;
}