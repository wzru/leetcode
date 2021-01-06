#include <iostream>
#include <set>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=929 lang=cpp
 *
 * [929] 独特的电子邮件地址
 */

// @lc code=start
class Solution {
  public:
    int numUniqueEmails(vector<string>& emails)
    {
        set<string> diff_emails;
        for (const auto& e : emails) {
            auto   at_pos  = e.rfind('@');
            auto   local   = e.substr(0, at_pos);
            auto dot_pos = local.find('.');
            while (dot_pos != string::npos) {
                local.erase(dot_pos, 1);
                dot_pos = local.find('.', dot_pos);
            }
            auto add_pos = local.find('+');
            if (add_pos != string::npos) { local = local.substr(0, add_pos); }
            auto email = local + e.substr(at_pos, e.size() - at_pos);
            // cout << "email=" << email << endl;
            diff_emails.insert(email);
        }
        return diff_emails.size();
    }
};
// @lc code=end
int main()
{
    Solution s;
    auto vs = vector<string>{"test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"};
    s.numUniqueEmails(vs);
    return 0;
}