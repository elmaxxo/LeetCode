/*
 * Given two strings s and t, return true if t is an anagram of s, and false otherwise.
 * 
 * An Anagram is a word or phrase formed by rearranging the letters of a different word
 * or phrase, typically using all the original letters exactly once.
 * 
 * Example 1:
 * 
 * Input: s = "anagram", t = "nagaram"
 * Output: true
 * Example 2:
 * 
 * Input: s = "rat", t = "car"
 * Output: false
 *  
 * Constraints:
 * 
 * 1 <= s.length, t.length <= 5 * 10^4
 * s and t consist of lowercase English letters.
 */

#include <cassert>
#include <string>

using namespace std;

class Solution {
public:
        static inline void count_letters(string s, int *letter_counter) {
                const int sz = s.size();
                for (int i = 0; i < sz; ++i) {
                        ++letter_counter[s[i] - 'a'];
                }
        }

        bool isAnagram(string s, string t) {
                const int sz1 = s.size();
                const int sz2 = t.size();
                if (sz1 != sz2)
                        return false;
                
                const int n_letters = 'z' - 'a' + 1;
                int letter_counter1[n_letters] = {};
                int letter_counter2[n_letters] = {};

                count_letters(s, letter_counter1);
                count_letters(t, letter_counter2);
                for (int i = 0; i < n_letters; ++i) {
                        if (letter_counter1[i] != letter_counter2[i])
                                return false;
                }
                return true;
        }
};

int main() {
        Solution solution;
        assert(solution.isAnagram("abc", "abc"));
        assert(solution.isAnagram("bca", "abc"));
        assert(solution.isAnagram("cba", "abc"));
        assert(!solution.isAnagram("aa", "abc"));
        assert(!solution.isAnagram("aab", "abc"));
        assert(!solution.isAnagram("abcd", "abc"));
        assert(!solution.isAnagram("abcd", "abc"));
}