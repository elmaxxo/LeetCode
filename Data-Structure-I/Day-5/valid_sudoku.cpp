/*
 * Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to
 * be validated according to the following rules:
 * 
 * Each row must contain the digits 1-9 without repetition.
 * Each column must contain the digits 1-9 without repetition.
 * Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
 * Note:
 * 
 * A Sudoku board (partially filled) could be valid but is not necessarily solvable.
 * Only the filled cells need to be validated according to the mentioned rules.
 * 
 * Example 1:
 * 
 * Input: board = 
 * [["5","3",".",".","7",".",".",".","."]
 * ,["6",".",".","1","9","5",".",".","."]
 * ,[".","9","8",".",".",".",".","6","."]
 * ,["8",".",".",".","6",".",".",".","3"]
 * ,["4",".",".","8",".","3",".",".","1"]
 * ,["7",".",".",".","2",".",".",".","6"]
 * ,[".","6",".",".",".",".","2","8","."]
 * ,[".",".",".","4","1","9",".",".","5"]
 * ,[".",".",".",".","8",".",".","7","9"]]
 * Output: true
 * Example 2:
 * 
 * Input: board = 
 * [["8","3",".",".","7",".",".",".","."]
 * ,["6",".",".","1","9","5",".",".","."]
 * ,[".","9","8",".",".",".",".","6","."]
 * ,["8",".",".",".","6",".",".",".","3"]
 * ,["4",".",".","8",".","3",".",".","1"]
 * ,["7",".",".",".","2",".",".",".","6"]
 * ,[".","6",".",".",".",".","2","8","."]
 * ,[".",".",".","4","1","9",".",".","5"]
 * ,[".",".",".",".","8",".",".","7","9"]]
 * Output: false
 * Explanation: Same as Example 1, except with the 5 in the top left corner being
 * modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.
 */

#include <cassert>
#include <iostream>
#include <vector>
#include <ctype.h>

using namespace std;

class Solution {
public:
        static const int N_COLUMNS = 9;
        static const int N_ROWS = 9;
        static int digits[9];     
    
        bool verify_digits() {
                for (int i = 0; i < N_COLUMNS; ++i) {
                        if (digits[i] > 1) return false;
                }
                return true;
        }
    
        void digits_reset() {
                for (int i = 0; i < N_ROWS; ++i) {
                        digits[i] = 0;
                }
        }
    
        bool columns_verify(vector<vector<char>>& board, int c) {
                digits_reset();
        
                for (int i = 0; i < N_COLUMNS; ++i) {
                if (isdigit(board[i][c]))
                        ++digits[board[i][c] - '1']; 
                }
        
                return verify_digits();
        }
    
        bool raws_verify(vector<vector<char>>& board, int r) {
                digits_reset();
        
                for (int i = 0; i < N_ROWS; ++i) {
                        if (isdigit(board[r][i]))
                                ++digits[board[r][i] - '1']; 
                }
        
                return verify_digits();
        }    
    
        bool square_verify(vector<vector<char>>& board, int r, int c) {
                digits_reset();

                for (int i = r - 1; i <= r + 1; ++i) {
                        for (int j = c - 1; j <= c + 1; ++j) {
                                if (isdigit(board[i][j]))
                                        ++digits[board[i][j] - '1'];
                        }
                }
        
                return verify_digits();
        }
    
        bool isValidSudoku(vector<vector<char>>& board) {
                for (int i = 0; i < N_COLUMNS; ++i) {
                        if (!columns_verify(board, i))
                                return false;
                }
                for (int i = 0; i < N_ROWS; ++i) {
                        if (!raws_verify(board, i))
                                return false;
                }
                for (int i = 1; i < N_ROWS; i += 3) {
                        for (int j = 1; j < N_COLUMNS; j += 3) {
                                if (!square_verify(board, i, j))
                                        return false;
                        }
                }
                return true;
        }
};

int Solution::digits[9] = {};

int main() {
        assert("It works! Don't you see?");
        return 0;
}