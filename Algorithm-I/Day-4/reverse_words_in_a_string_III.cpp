/*
 * Given a string s, reverse the order of characters in eachword within
 * a sentence while still preserving whitespace and initial word order.
 * 
 * Example 1:
 * 
 * Input: s = "Let's take LeetCode contest"
 * Output: "s'teL ekat edoCteeL tsetnoc"
 * Example 2:
 * 
 * Input: s = "God Ding"
 * Output: "doG gniD"
 */

#include <cassert>
#include <string>
#include <utility>
#include <algorithm>
#include <iostream>

using namespace std;

#include <ctype.h>
#include <algorithm>

class Solution {
public:
        string reverseWords(string s) {
                auto wbeg = s.begin();
                auto wend = s.begin();
                auto send = s.end();
                auto is_space = [](char c) { return isspace(c);  };
                while (true) {
                        if (wend == send)
                                break;
                        wbeg = find_if_not(wend, send, is_space);
                        if (wbeg == send)
                                break;
                        wend = find_if(wbeg, send, is_space);
                        reverse(wbeg, wend);
                }
        return s;
    }
};

int main() {
        string s = " abc def 123";
        string expect = " cba fed 321";

        Solution solution;
        auto reversed = solution.reverseWords(s);
        assert(reversed == expect);
        reversed = solution.reverseWords(reversed);
        assert(reversed == s);
        return 0;
}