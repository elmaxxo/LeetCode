/*
 * Given an integer array nums sorted in non-decreasing order,
 * return an array of the squares of each number sorted in non-decreasing order.
 * 
 * Example 1:
 * 
 * Input: nums = [-4,-1,0,3,10]
 * Output: [0,1,9,16,100]
 * Explanation: After squaring, the array becomes [16,1,0,9,100].
 * After sorting, it becomes [0,1,9,16,100].
 * Example 2:
 * 
 * Input: nums = [-7,-3,2,3,11]
 * Output: [4,9,9,49,121]
 *  
 * Constraints:
 * 
 * 1 <= nums.length <= 104
 * -104 <= nums[i] <= 104
 * nums is sorted in non-decreasing order.
 * 
 * Follow up: Squaring each element and sorting the new array is very trivial,
 * could you find an O(n) solution using a different approach?
 */

#include <cassert>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
private:
        int sqr(int n) { return n*n; };
public:
        vector<int> sortedSquares(vector<int>& nums) {
                auto l = begin(nums);
                auto r = rbegin(nums);
                vector<int> result(nums.size());

                for (int i = result.size() - 1; i != -1; --i) {
                        if (sqr(*l) < sqr(*r))
                                result[i] = sqr(*r++);
                        else
                                result[i] = sqr(*l++);
                }
                return result;
        }
};

int main() {
        vector<int> v1 = {-5, 0, 3, 4};
        vector<int> v2 = {-5, -1};
        vector<int> v3 = {1, 5, 8};
        vector<int> v4 = {-2, -1, 0, 8};
        vector<int> v5 = {};

        Solution solution;
        vector<int> v;
        v = solution.sortedSquares(v1);
        assert(is_sorted(begin(v), end(v)) && "v1");
        v = solution.sortedSquares(v2);
        assert(is_sorted(begin(v), end(v)) && "v2");
        v = solution.sortedSquares(v3);
        assert(is_sorted(begin(v), end(v)) && "v3");
        v = solution.sortedSquares(v4);
        assert(is_sorted(begin(v), end(v)) && "v4");
        v = solution.sortedSquares(v5);
        assert(is_sorted(begin(v), end(v)) && "v5");
        return 0;
}