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

using namespace std;

class Solution {
public:
        bool checkInclusion(string s1, string s2) {
                const int n_letters = 'z' - 'a' + 1;
                int storage1[n_letters] = {};
                int storage2[n_letters] = {};
                const int sz1 = s1.size();
                const int sz2 = s2.size();
                if (sz2 < sz1) {
                        return false;
                }
                for (int i = 0; i < sz1; ++i) {
                        ++storage1[s1[i] - 'a'];
                        ++storage2[s2[i] - 'a'];
                }
                
                for (int i = 0; i < sz2 - sz1; ++i) {
                        if (equal(storage1, storage1 + n_letters, storage2))
                                return true;
                        --storage2[s2[i] - 'a'];
                        ++storage2[s2[i + sz1] - 'a'];
                }
                return equal(storage1, storage1 + n_letters, storage2);
        }
};

int main() {
        Solution solution;
        assert(solution.checkInclusion("ab", "ab"));
        assert(solution.checkInclusion("ab", "ba"));
        assert(!solution.checkInclusion("abc", "ba"));
        assert(solution.checkInclusion("abc", "bac"));
        assert(solution.checkInclusion("ac", "bac"));
        assert(solution.checkInclusion("ac", "bdwaszxaaadcadsaw"));
        return 0;
}