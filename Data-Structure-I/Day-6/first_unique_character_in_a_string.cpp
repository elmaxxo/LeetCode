/*
 * Given a string s, find the first non-repeating character in it and
 * return its index. If it does not exist, return -1.
 * 
 * Example 1:
 * 
 * Input: s = "leetcode"
 * Output: 0
 * Example 2:
 * 
 * Input: s = "loveleetcode"
 * Output: 2
 * Example 3:
 * 
 * Input: s = "aabb"
 * Output: -1
 *  
 * 
 * Constraints:
 * 
 * 1 <= s.length <= 105
 * s consists of only lowercase English letters.
 */

#include <cassert>
#include <string>

using namespace std;

class Solution {
public:
        int firstUniqChar(string s) {
                const int n_letters = 'z' - 'a' + 1;
                int letter_counter[n_letters] = {};

                for (int i = 0, sz = s.size(); i < sz; ++i) {
                        ++letter_counter[s[i] - 'a'];
                }

                for (int i = 0, sz = s.size(); i < sz; ++i) {
                        if (letter_counter[s[i] - 'a'] == 1)
                                return i;
                }

                return -1;
        }
};

int main() {
        Solution solution;
        assert(solution.firstUniqChar("abcd") == 0);
        assert(solution.firstUniqChar("aabcd") == 2);
        assert(solution.firstUniqChar("aabbccdd") == -1);
        assert(solution.firstUniqChar("a") == 0);

        return 0;
}