/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
class Solution {
  public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        int cnt = nums1.size() + nums2.size();
        int ans = 0;
        int l = 0, r = nums1.size() - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            int res = lower_bound(nums2.begin(), nums2.end(), nums1[mid]) - nums2.begin() + mid - 1;
            if (res > cnt / 2)
                r = mid - 1;
            else if (res < (cnt - 1) / 2)
                l = mid + 1;
            else {
                if (cnt & 1)
                    return nums1[mid];
                else {
                    int res1 = lower_bound(nums2.begin(), nums2.end(), nums1[mid + ]) - nums2.begin() + mid - 1;
                }
                break;
            }
        }
    }
};
// @lc code=end
