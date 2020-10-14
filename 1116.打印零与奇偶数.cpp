/*
 * @lc app=leetcode.cn id=1116 lang=cpp
 *
 * [1116] 打印零与奇偶数
 */

// @lc code=start
class ZeroEvenOdd {
  private:
    int                n;
    condition_variable cv;
    mutex              mtx;
    int                cnt = 0;

  public:
    ZeroEvenOdd(int n)
    {
        this->n = n;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber)
    {
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this]() { return (cnt & 1) == 0; });
            // printFoo() outputs "foo". Do not change or remove this line.
            printNumber(0);
            ++cnt;
            cv.notify_all();
        }
    }

    void even(function<void(int)> printNumber)
    {
        for (int i = 2; i <= n; i += 2) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this]() { return (cnt & 1) == 1 && ((cnt >> 1) & 1) == 1; });
            // printFoo() outputs "foo". Do not change or remove this line.
            printNumber(i);
            ++cnt;
            cv.notify_one();
        }
    }

    void odd(function<void(int)> printNumber)
    {
        for (int i = 1; i <= n; i += 2) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this]() { return (cnt & 1) == 1 && ((cnt >> 1) & 1) == 0; });
            // printFoo() outputs "foo". Do not change or remove this line.
            printNumber(i);
            ++cnt;
            cv.notify_one();
        }
    }
};
// @lc code=end
