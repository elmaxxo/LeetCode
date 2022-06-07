/*
 * The Tribonacci sequence Tn is defined as follows: 
 * 
 * T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.
 * 
 * Given n, return the value of Tn.
 * 
 *  
 * 
 * Example 1:
 * 
 * Input: n = 4
 * Output: 4
 * Explanation:
 * T_3 = 0 + 1 + 1 = 2
 * T_4 = 1 + 1 + 2 = 4
 * Example 2:
 * 
 * Input: n = 25
 * Output: 1389537
 *  
 * 
 * Constraints:
 * 
 * 0 <= n <= 37
 * The answer is guaranteed to fit within a 32-bit integer, ie. answer <= 2^31 - 1.
 */

#include <cassert>

class Solution {
public:
        int fib(int n) {
                int nums[n + 3];
                nums[0] = 0;
                nums[1] = 1;
                nums[2] = 1;
                for (int i = 3; i <= n; ++i) {
                        nums[i] = nums[i-1] + nums[i-2] + nums[i-3];
                }
                return nums[n];
        }
};

int main() {
        Solution solution;
        assert(solution.fib(0) == 0);
        assert(solution.fib(1) == 1);
        assert(solution.fib(2) == 1);
        assert(solution.fib(3) == 2);
        assert(solution.fib(4) == 4);
        assert(solution.fib(25) == 1389537);
        return 0;
}