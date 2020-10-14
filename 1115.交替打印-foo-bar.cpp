/*
 * @lc app=leetcode.cn id=1115 lang=cpp
 *
 * [1115] 交替打印FooBar
 */

// @lc code=start
class FooBar {
  private:
    int                n;
    condition_variable cv;
    mutex              mtx;
    int                cnt;

  public:
    FooBar(int n)
    {
        this->n = n;
        cnt     = n << 1;
    }

    void foo(function<void()> printFoo)
    {
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this]() { return (cnt & 1) == 0; });
            // printFoo() outputs "foo". Do not change or remove this line.
            printFoo();
            --cnt;
            cv.notify_one();
        }
    }

    void bar(function<void()> printBar)
    {
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this]() { return (cnt & 1) == 1; });
            // printBar() outputs "bar". Do not change or remove this line.
            printBar();
            --cnt;
            cv.notify_one();
        }
    }
};
// @lc code=end
