/*
    @lc app=leetcode.cn id=42 lang=cpp

    [42] 接雨水
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// @lc code=start
class Solution
{
public:
    stack<int> s;
    vector<int> l, r;
    int trap (vector<int> &height)
    {
        int n = height.size(), ans = 0;
        if (!n)
        {
            return 0;
        }
        l.resize (n), r.resize (n);
        l[0] = height[0];
        for (int i = 1; i < n; ++i)
        {
            l[i] = max (height[i], l[i - 1]);
        }
        r[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; --i)
        {
            r[i] = max (height[i], r[i + 1]);
        }
        for (int i = 0; i < n; ++i)
        {
            int lm = l[i], rm = r[i];
            int m = min (lm, rm);
            if (m > height[i])
            {
                ans += m - height[i];
            }
        }
        // s.push (height[0]);
        // for (int i = 1; i < height.size(); ++i)
        // {
        //     if (height[i] <= height[i - 1])
        //     {
        //         s.push (height[i]);
        //     }
        //     else
        //     {
        //         while (!s.empty() && s.top() <= height[i])
        //         {
        //             ans += height[i] - s.top();
        //             s.pop();
        //         }
        //         s.push(height[i]);
        //     }
        // }
        return ans;
    }
};
// @lc code=end

