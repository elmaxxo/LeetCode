/*
 * Given two strings s1 and s2, return true if s2
 * contains a permutation of s1, or false otherwise.
 *
 * In other words, return true if one of s1's permutations is the substring of s2.
 *
 * Example 1:
 *
 * Input: s1 = "ab", s2 = "eidbaooo"
 * Output: true
 * Explanation: s2 contains one permutation of s1 ("ba").
 * Example 2:
 *
 * Input: s1 = "ab", s2 = "eidboaoo"
 * Output: false
 *
 * Constraints:
 *
 * 1 <= s1.length, s2.length <= 104
 * s1 and s2 consist of lowercase English letters.
 */

#include <cassert>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:

	bool checkInclusion(string s1, string s2) {
		const size_t sz1 = s1.size();
		const size_t sz2 = s2.size();

		vector<size_t> letters1('z' + 1);
		vector<size_t> letters2('z' + 1);
		for (size_t i = 0; i < sz1; ++i) {
			letters1[s1[i]] += 1;
			letters2[s2[i]] += 1;
		}

		for (size_t i = 0; i < sz2 - sz1; ++i) {
			if (letters1 == letters2)
				return true;
			letters2[s2[i + sz1]] += 1;
			letters2[s2[i]] -= 1;
		}
		return letters1 == letters2;
	}
};

int main() {
	Solution solution;
	assert(solution.checkInclusion("ab", "ab"));
	assert(solution.checkInclusion("ab", "ba"));
	assert(solution.checkInclusion("abc", "bac"));
	assert(solution.checkInclusion("ac", "bac"));
	assert(solution.checkInclusion("ac", "bdwaszxaaadcadsaw"));
	return 0;
}
