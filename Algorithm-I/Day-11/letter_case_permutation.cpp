/*
 * Given a string s, you can transform every letter individually to be lowercase
 * or uppercase to create another string.
 *
 * Return a list of all possible strings we could create. Return the output in any order.
 *
 * Example 1:
 *
 * Input: s = "a1b2"
 * Output: ["a1b2","a1B2","A1b2","A1B2"]
 * Example 2:
 *
 * Input: s = "3z4"
 * Output: ["3z4","3Z4"]
 *
 * Constraints:
 *
 * 1 <= s.length <= 12
 * s consists of lowercase English letters, uppercase English letters, and digits.
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	vector<string> letterCasePermutation(string s)
	{
		vector<string> permutations;
		backtrack(permutations, s);
		return permutations;
    	}
private:
	void backtrack(vector<string>& permutations, string& s, size_t idx = 0)
	{
		if (idx == s.size()) {
			permutations.push_back(s);
			return;
		}

		if (isdigit(s[idx])) {
			backtrack(permutations, s, idx + 1);
		} else if (islower(s[idx])) {
			backtrack(permutations, s, idx + 1);
			s[idx] = toupper(s[idx]);
			backtrack(permutations, s, idx + 1);
		} else { /* isupper */
			backtrack(permutations, s, idx + 1);
			s[idx] = tolower(s[idx]);
			backtrack(permutations, s, idx + 1);
		}
	}
};

int main()
{
	string s = "aD56e";

	Solution solution;
	auto permutations = solution.letterCasePermutation(s);

	for (const auto& s : permutations)
		cerr << s << endl;

	return 0;
}
