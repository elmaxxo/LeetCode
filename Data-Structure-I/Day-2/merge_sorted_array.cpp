/*
 * You are given two integer arrays nums1 and nums2, sorted in non-decreasing order,
 * and two integers m and n, representing the number of elements in nums1 and nums2 respectively.
 * 
 * Merge nums1 and nums2 into a single array sorted in non-decreasing order.
 * 
 * The final sorted array should not be returned by the function,
 * but instead be stored inside the array nums1. To accommodate this,
 * nums1 has a length of m + n, where the first m elements denote the
 * elements that should be merged, and the last n elements are set to 0
 * and should be ignored. nums2 has a length of n.
 * 
 * Example 1:
 * 
 * Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
 * Output: [1,2,2,3,5,6]
 * Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
 * The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.
 * Example 2:
 * 
 * Input: nums1 = [1], m = 1, nums2 = [], n = 0
 * Output: [1]
 * Explanation: The arrays we are merging are [1] and [].
 * The result of the merge is [1].
 * Example 3:
 * 
 * Input: nums1 = [0], m = 0, nums2 = [1], n = 1
 * Output: [1]
 * Explanation: The arrays we are merging are [] and [1].
 * The result of the merge is [1].
 * Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1. 
 * 
 * Constraints:
 * 
 * nums1.length == m + n
 * nums2.length == n
 * 0 <= m, n <= 200
 * 1 <= m + n <= 200
 * -109 <= nums1[i], nums2[j] <= 109
 */

#include <cassert>
#include <vector>
#include <algorithm>
#include <climits>
#include <iostream>

using namespace std;

class Solution {
public:
        void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
                int *p1 = nullptr, *p1_border = nullptr;
                int *p2 = nullptr, *p2_border = nullptr;
                if (m) {
                        p1 = nums1.data() + m - 1;
                        p1_border = nums1.data() - 1;
                }
                if (n) {
                        p2 = nums2.data() + n - 1;
                        p2_border = nums2.data() - 1;
                }
                for (int i = m + n - 1; i != -1; --i) {
                        auto val1 = (p1 != p1_border) ? *p1 : INT_MIN;
                        auto val2 = (p2 != p2_border) ? *p2 : INT_MIN;
                        if (val1 < val2) {
                                nums1[i] = val2;
                                p2--;
                        } else {
                                nums1[i] = val1;
                                p1--;
                        }
                }
        }
};

int main() {
        vector<int> v1 = {4, 7, 10, 20};
        vector<int> v2 = {2, 8, 10, 15};
        auto v1_size = v1.size();
        auto v2_size = v2.size();
        v1.resize(v1_size + v2_size);

        Solution solution;
        solution.merge(v1, v1_size, v2, v2_size);
        for (auto n : v1)
                cout << n << ' ';
        cout << endl;
        assert(is_sorted(v1.begin(), v1.end()));
        return 0;
}