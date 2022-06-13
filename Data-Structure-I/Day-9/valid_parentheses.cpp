/*
 * Given a string s containing just the characters '(', ')', '{', '}',
 * '[' and ']', determine if the input string is valid.
 * 
 * An input string is valid if:
 * 
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 *  
 * Example 1:
 * 
 * Input: s = "()"
 * Output: true
 * Example 2:
 * 
 * Input: s = "()[]{}"
 * Output: true
 * Example 3:
 * 
 * Input: s = "(]"
 * Output: false
 *  
 * Constraints:
 * 
 * 1 <= s.length <= 104
 * s consists of parentheses only '()[]{}'.
 */

#include <cassert>
#include <string>

using namespace std;

class Solution {
public:
        bool isValid(string s) {
                char parents[105] = {};
                int n_parents = 0;
                for (char c : s) {
                        if (c == '(' || c == '[' || c == '{') {
                                parents[n_parents++] = c;
                        } else {
                                if ((n_parents == 0) || 
                                    (parents[n_parents - 1] == '(' && c != ')') ||
                                    (parents[n_parents - 1] == '[' && c != ']') ||
                                    (parents[n_parents - 1] == '{' && c != '}'))
                                        return false;
                                --n_parents;
                        }
                }                
                return n_parents == 0;
        }
};

int main() {
        Solution solution;
        assert(solution.isValid("()"));
        assert(solution.isValid("[]"));
        assert(solution.isValid("{}"));
        assert(solution.isValid("(){}[]"));
        assert(solution.isValid("[{}]"));
        assert(solution.isValid("([{}])"));
        assert(solution.isValid("(){}[]([{}])"));
        
        assert(!solution.isValid(")"));
        assert(!solution.isValid("("));
        assert(!solution.isValid("]["));
        assert(!solution.isValid("([)]"));
}