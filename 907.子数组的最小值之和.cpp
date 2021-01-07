class Solution {
  public:
    int sumSubarrayMins(vector<int>& arr)
    {
        const int   MOD = 1e9 + 7;
        int         n   = arr.size();
        stack<int>  s;
        vector<int> lm(n, -1), rm(n, n);
        for (int i = 0; i < n; ++i) {
            while (s.size() && arr[s.top()] >= arr[i]) s.pop();
            if (s.size()) lm[i] = s.top();
            s.push(i);
        }
        s = stack<int>();
        for (int i = n - 1; i >= 0; --i) {
            while (s.size() && arr[s.top()] > arr[i]) s.pop();
            if (s.size()) rm[i] = s.top();
            s.push(i);
        }
        // for (int i = 0; i < n; ++i) cout << "l=" << lm[i] << " r=" << rm[i] << endl;
        int sum = 0;
        for (int i = 0; i < n; ++i) { sum = (sum + (long long)arr[i] * (rm[i] - i) * (i - lm[i]) % MOD) % MOD; }
        return sum;
    }
};