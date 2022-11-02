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
#include <unordered_map>

using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		unordered_map<char, size_t> positions;
		size_t max_length = 0;
		size_t length = 0;

		for (size_t i = 0, sz = s.size(); i < sz; ++i) {
			if (positions.find(s[i]) == positions.end()) {
				positions[s[i]] = i;
				length += 1;
				max_length = max(max_length, length);
			} else {
				size_t duplicate_lpos = positions[s[i]];
				for (size_t j = i - length; j < duplicate_lpos; j++)
					positions.erase(s[j]);
				length = i - duplicate_lpos;
				positions[s[i]] = i;
			}
		}

		return max_length;
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
