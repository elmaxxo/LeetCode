/*
 * Write a function that reverses a string.
 * The input string is given as an array of characters s.
 * 
 * You must do this by modifying the input array in-place
 * with O(1) extra memory.
 * 
 * Example 1:
 * 
 * Input: s = ["h","e","l","l","o"]
 * Output: ["o","l","l","e","h"]
 * Example 2:
 * 
 * Input: s = ["H","a","n","n","a","h"]
 * Output: ["h","a","n","n","a","H"]
 *  
 * 
 * Constraints:
 * 
 * 1 <= s.length <= 105
 * s[i] is a printable ascii character.
 */

#include <cassert>
#include <vector>
#include <utility>

using namespace std;

class Solution {
public:
        void reverseString(vector<char>& s) {
                for (int i = 0, sz = s.size(); i < sz / 2; ++i) {
                        swap(s[i], s[sz - i - 1]);
                }
        }
};

int main() {
        vector<char> s = {'1', '2', '3'};

        Solution solution;
        solution.reverseString(s);
        assert(s[0] = '3');
        assert(s[1] = '2');
        assert(s[2] = '1');
        return 0;
}