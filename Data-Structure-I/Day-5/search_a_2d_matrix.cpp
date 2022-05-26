/*
 * Write an efficient algorithm that searches for a value target in an m x n
 * integer matrix matrix. This matrix has the following properties:
 * 
 * Integers in each row are sorted from left to right.
 * The first integer of each row is greater than the last integer of the previous row. 
 * 
 * Example 1:
 * 
 * Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
 * Output: true
 * Example 2:
 * 
 * Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
 * Output: false
 * 
 * Constraints:
 * 
 * m == matrix.length
 * n == matrix[i].length
 * 1 <= m, n <= 100
 * -10^4 <= matrix[i][j], target <= 10^4
 */

#include <cassert>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
                size_t row_size = matrix[0].size();
                size_t l = 0;
                size_t r = matrix.size() * row_size;
                while (l != r) {
                        auto m = l + (r - l) / 2;
                        auto val = matrix[m / row_size][m % row_size];
                        if (val == target) {
                                return true;
                        } else if (val < target) {
                                l = m + 1;
                        } else {
                                r = m;
                        }
                }
                return false;
        }                
};

int main() {
        vector<vector<int>> matrix = {
                { 1, 2, 3, 4, 5 },
                { 6, 7, 8, 9, 10 },
                { 11, 20, 30, 40, 50 }
        };

        Solution solution;
        assert(solution.searchMatrix(matrix, 1));
        assert(solution.searchMatrix(matrix, 2));
        assert(solution.searchMatrix(matrix, 5));
        assert(solution.searchMatrix(matrix, 6));
        assert(solution.searchMatrix(matrix, 6));
        assert(solution.searchMatrix(matrix, 10));
        assert(solution.searchMatrix(matrix, 11));
        assert(solution.searchMatrix(matrix, 50));
        assert(!solution.searchMatrix(matrix, 22));
        assert(!solution.searchMatrix(matrix, 33));
        assert(!solution.searchMatrix(matrix, 44));
        return 0;
}