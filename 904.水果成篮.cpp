#include <iostream>
#include <map>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=904 lang=cpp
 *
 * [904] 水果成篮
 */

// @lc code=start
class Solution {
  public:
    int totalFruit(vector<int>& tree)
    {
        map<int, int> cnt;
        int           l = 0, r = 1, ans = 1;
        ++cnt[tree[0]];
        while (r < tree.size()) {
            ans = max(ans, r - l);
            if (cnt.count(tree[r])) {
                ++cnt[tree[r]];
                ++r;
            }
            else {
                while(cnt.size()>=2) {
                    int c = --cnt[tree[l]];
                    if(!c) {
                        cnt.erase(tree[l]);
                    }
                    ++l;
                }
                ++cnt[tree[r]];
                ++r;
            }
        }
        ans = max(ans, r - l);
        return ans;
    }
};
// @lc code=end
int main() {
    Solution s;
    auto vi = vector<int> {3,3,3,1,2,1,1,2,3,3,4};
    s.totalFruit(vi);
    return 0;
}