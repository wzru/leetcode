/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
  public:
    int lengthOfLongestSubstring(string s)
    {
        int  l      = s.size();
        bool b[256] = {0};
        int  cnt = 0, ans = 0, head = 0;
        for (int tail = 0; tail < l; ++tail) {
            if (!b[s[tail]]) { b[s[tail]] = 1; }
            else {
                while (s[head] != s[tail]) b[s[head]] = 0, ++head;
                ++head;
            }
            ans = max(ans, tail - head + 1);
        }
        return ans;
    }
};
// @lc code=end
