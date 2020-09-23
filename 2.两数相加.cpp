/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
  public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode *sum = new ListNode(), *p = sum;
        int       r = 0;
        while (l1 != nullptr || l2 != nullptr) {
            if (l1 == nullptr)
                p->val = l2->val + r, l2 = l2->next;
            else if (l2 == nullptr)
                p->val = l1->val + r, l1 = l1->next;
            else
                p->val = (l1->val + l2->val + r), l1 = l1->next, l2 = l2->next;
            if (p->val >= 10) {
                r = 1;
                p->val -= 10;
            }
            else {
                r = 0;
            }
            if (l1 != nullptr || l2 != nullptr)
                p->next = new ListNode(0), p = p->next;
            else if (r)
                p->next = new ListNode(r);
        }
        return sum;
    }
};
// @lc code=end
