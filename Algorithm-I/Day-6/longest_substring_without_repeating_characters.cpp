/*
 * Given a string s, find the length of the longest substring without repeating characters.
 * 
 * Example 1:
 * 
 * Input: s = "abcabcbb"
 * Output: 3
 * Explanation: The answer is "abc", with the length of 3.
 * Example 2:
 * 
 * Input: s = "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 * Example 3:
 * 
 * Input: s = "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3.
 * Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 *  
 * Constraints:
 * 
 * 0 <= s.length <= 5 * 104
 * s consists of English letters, digits, symbols and spaces.
 */

#include <cassert>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

class Solution {
public:
        struct char_info {
                int quantity;
                int position;
        };

        int lengthOfLongestSubstring(string s) {
                const int n_chars = 256;
                char_info chars[n_chars] = {};

                int i = 0;
                int max_lenght = 0;
                int cur_lenght = 0;
                const int sz = s.size();
                while (i < sz) {
                        int idx = s[i];
                        if (chars[idx].quantity < 1) {
                                chars[idx].quantity = 1;
                                chars[idx].position = i;
                                max_lenght = max(max_lenght, ++cur_lenght);
                                ++i;
                        } else {
                                int new_pos = chars[idx].position + 1;
                                for (int j = i - cur_lenght; j <= chars[idx].position; ++j)
                                        chars[(int)s[j]] = {};
                                cur_lenght = i - new_pos;
                        }
                }
                return max_lenght;
        }
};

int main() {
        Solution solution;
        assert(solution.lengthOfLongestSubstring("abcder") == 6);
        assert(solution.lengthOfLongestSubstring("abcabcbb") == 3);
        assert(solution.lengthOfLongestSubstring("abcdbcbb") == 4);
        assert(solution.lengthOfLongestSubstring("ababc") == 3);
        assert(solution.lengthOfLongestSubstring("abcdabcc") == 4);
        assert(solution.lengthOfLongestSubstring("abcabcbb") == 3);
        return 0;
}