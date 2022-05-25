/*
 * Given an integer numRows, return the first numRows of Pascal's triangle.
 * 
 * In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:
 * 
 * Example 1:
 * 
 * Input: numRows = 5
 * Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
 * Example 2:
 * 
 * Input: numRows = 1
 * Output: [[1]]
 *  
 * Constraints:
 * 
 * 1 <= numRows <= 30
 */

#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
        vector<vector<int>> generate(int numRows) {
                vector<vector<int>> triangle(numRows);
                for (int row = 0; row < numRows; ++row) {
                        triangle[row].resize(row + 1);
                        triangle[row][0] = 1;
                        triangle[row][row] = 1;
                        for (int i = 1; i < row; ++i) {
                                triangle[row][i] = triangle[row - 1][i - 1] + triangle[row - 1][i]; 
                        }
                }
                return triangle;
        }
};

int main() {
        Solution solution;
        auto triangle = solution.generate(3);
        assert(triangle[0][0] == 1);
        assert(triangle[1][0] == 1);
        assert(triangle[1][1] == 1);
        assert(triangle[2][0] == 1);
        assert(triangle[2][1] == 2);
        assert(triangle[2][2] == 1);
        return 0;
}