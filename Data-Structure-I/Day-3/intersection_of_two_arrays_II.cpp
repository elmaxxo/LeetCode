/*
 * Given two integer arrays nums1 and nums2, return an array of their intersection.
 * Each element in the result must appear as many times as it shows in both arrays
 * and you may return the result in any order. 
 * 
 * Example 1:
 * 
 * Input: nums1 = [1,2,2,1], nums2 = [2,2]
 * Output: [2,2]
 * Example 2:
 * 
 * Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 * Output: [4,9]
 * Explanation: [9,4] is also accepted.
 *  
 * Constraints:
 * 
 * 1 <= nums1.length, nums2.length <= 1000
 * 0 <= nums1[i], nums2[i] <= 1000
 *  
 * Follow up:
 * 
 * What if the given array is already sorted? How would you optimize your algorithm?
 * What if nums1's size is small compared to nums2's size? Which algorithm is better?
 * What if elements of nums2 are stored on disk, and the memory is limited such that
 * you cannot load all elements into the memory at once?
 */

#include <cassert>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
        vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
                sort(begin(nums1), end(nums1));
                sort(begin(nums2), end(nums2));

                int idx1 = 0, sz1 = nums1.size();
                int idx2 = 0, sz2 = nums2.size();
                vector<int> intersection;
                while (idx1 < sz1 && idx2 < sz2) {
                        int v1 = nums1[idx1];
                        int v2 = nums2[idx2];
                        if (v1 == v2) {
                                intersection.push_back(v1);
                                ++idx1;
                                ++idx2;
                        } else if (v1 < v2) {
                                ++idx1;
                        } else {
                                ++idx2;
                        }
                }
                return intersection;
        }
};

int main() {
        vector<int> v1 { 1, 2, 4, 5 };
        vector<int> v2 { 0, 1, 2, 3, 4, 5 };

        Solution solution;
        auto intersection = solution.intersect(v1, v2);
        assert(intersection[0] == 1);
        assert(intersection[1] == 2);
        assert(intersection[2] == 4);
        assert(intersection[3] == 5);
        return 0;
}