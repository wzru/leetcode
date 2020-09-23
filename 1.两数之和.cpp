/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
  public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        std::unordered_map<int, int> h;
        int                          l = nums.size();
        for (int i = 0; i < l; ++i) h[nums[i]] = i;
        for (int i = 0; i < l; ++i) {
            auto it = h.find(target - nums[i]);
            if (it != h.end() && i != it->second) { return vector<int>{i, it->second}; }
        }
        return vector<int>{};
    }
};
// @lc code=end
