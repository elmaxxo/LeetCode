/*
 * Given two strings ransomNote and magazine, return true if ransomNote
 * can be constructed from magazine and false otherwise.
 * 
 * Each letter in magazine can only be used once in ransomNote.
 *  
 * Example 1:
 * 
 * Input: ransomNote = "a", magazine = "b"
 * Output: false
 * Example 2:
 * 
 * Input: ransomNote = "aa", magazine = "ab"
 * Output: false
 * Example 3:
 * 
 * Input: ransomNote = "aa", magazine = "aab"
 * Output: true
 *  
 * 
 * Constraints:
 * 
 * 1 <= ransomNote.length, magazine.length <= 105
 * ransomNote and magazine consist of lowercase English letters.
 */

#include <cassert>
#include <string>

using namespace std;

class Solution {
public:
        bool canConstruct(string ransomNote, string magazine) {
                const int n_letters = 26;
                int ransom_note_collection[n_letters] = {};
                int magazine_collection[n_letters] = {};
        
                for (int i = 0, sz = ransomNote.size(); i < sz; ++i) {
                        ++ransom_note_collection[ransomNote[i] - 'a'];
                }
                for (int i = 0, sz = magazine.size(); i < sz; ++i) {
                        ++magazine_collection[magazine[i] - 'a'];
                }
        
                for (int i = 0; i < n_letters; ++i) {
                        if (magazine_collection[i] < ransom_note_collection[i])
                                return false;
                }
                return true;
        }
};

int main() {
        Solution solution;
        assert(solution.canConstruct("a", "a"));
        assert(solution.canConstruct("a", "aa"));
        assert(solution.canConstruct("a", "ab"));
        assert(solution.canConstruct("abc", "bca"));
        assert(solution.canConstruct("abc", "bcaqreq"));
        assert(!solution.canConstruct("abc", "baqreq"));
        assert(!solution.canConstruct("abcc", "abcb"));
        return 0;
}