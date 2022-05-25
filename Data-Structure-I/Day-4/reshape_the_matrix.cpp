/*
 * In MATLAB, there is a handy function called reshape which can reshape
 * an m x n matrix into a new one with a different size r x c keeping its original data.
 * 
 * You are given an m x n matrix mat and two integers r and c representing
 * the number of rows and the number of columns of the wanted reshaped matrix.
 * 
 * The reshaped matrix should be filled with all the elements of the original
 * matrix in the same row-traversing order as they were.
 * 
 * If the reshape operation with given parameters is possible and legal,
 * output the new reshaped matrix; Otherwise, output the original matrix.
 * 
 * Example 1:
 * 
 * Input: mat = [[1,2],[3,4]], r = 1, c = 4
 * Output: [[1,2,3,4]]
 * Example 2:
 * 
 * Input: mat = [[1,2],[3,4]], r = 2, c = 4
 * Output: [[1,2],[3,4]]
 *  
 * Constraints:
 * 
 * m == mat.length
 * n == mat[i].length
 * 1 <= m, n <= 100
 * -1000 <= mat[i][j] <= 1000
 * 1 <= r, c <= 300
 */

#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
        vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
                int n_elems = mat.size() * mat[0].size();
                if (n_elems != r * c || n_elems % r != 0 || n_elems % c != 0)
                        return mat;
                vector<int> elems(r*c);
                int r_sz = mat.size();
                int c_sz = mat[0].size();
                auto elems_begin = begin(elems);
                for (int i = 0; i < r_sz; ++i) {
                        copy(begin(mat[i]), end(mat[i]), elems_begin + i * c_sz);
                }

                vector<vector<int>> reshaped_mat(r); 
                for (int i = 0; i < r; ++i) {
                        reshaped_mat[i].resize(c);
                        copy(elems_begin + i * c, elems_begin + (i + 1) * c, begin(reshaped_mat[i]));        
                }

                return reshaped_mat;
        }
};

int main() {
        vector<vector<int>> mat = { {1, 2}, {3, 4} };

        Solution solution;
        auto reshaped = solution.matrixReshape(mat, 1, 4);
        assert(reshaped.size() == 1);
        assert(reshaped[0].size() == 4);
        assert(reshaped[0][0] == 1);
        assert(reshaped[0][1] == 2);
        assert(reshaped[0][2] == 3);
        assert(reshaped[0][3] == 4);

        return 0;
}