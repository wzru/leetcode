class Solution {
  public:
    int minDominoRotations(vector<int>& A, vector<int>& B)
    {
        vector<int> cand{A[0], B[0]};
        int         n   = A.size();
        int         ans = INT_MAX;
        for (auto v : cand) {
            int cnta = 0, cntb = 0, flag = 1;
            for (int i = 0; i < n; ++i)
                if (A[i] != v) {
                    if (B[i] == v)
                        ++cnta;
                    else {
                        flag = 0;
                        break;
                    }
                }
            if (flag) {
                for (int i = 0; i < n; ++i)
                    if (B[i] != v) {
                        if (A[i] == v) ++cntb;
                    }
                cnta = min(cnta, n - cnta), cntb = min(cntb, n - cntb);
                ans = min(ans, cnta), ans = min(ans, cntb);
            }
        }
        if (ans == INT_MAX) return -1;
        return ans;
    }
};