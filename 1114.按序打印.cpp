/*
 * @lc app=leetcode.cn id=1114 lang=cpp
 *
 * [1114] 按序打印
 */

// @lc code=start
class Foo {
    mutex              m1, m2;
    unique_lock<mutex> l1, l2;

  public:
    Foo() : l1(m1, try_to_lock), l2(m2, try_to_lock) {}

    void first(function<void()> printFirst)
    {
        printFirst();
        l1.unlock();
    }

    void second(function<void()> printSecond)
    {
        lock_guard<mutex> guard(m1);
        printSecond();
        l2.unlock();
    }

    void third(function<void()> printThird)
    {
        lock_guard<mutex> guard(m2);
        printThird();
    }
};
// @lc code=end
