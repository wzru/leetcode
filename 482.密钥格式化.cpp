class Solution {
  public:
    string licenseKeyFormatting(string S, int K)
    {
        vector<char> vc;
        const char*  s = S.c_str();
        for (auto c = s; *c; ++c) {
            if (isalnum(*c)) { vc.push_back(toupper(*c)); }
        }
        string res;
        int    n = vc.size(), cnt = 0;
        for (int i = 0; i < n % K; ++i) res += vc[i];
        if (n % K && n % K != n) res += '-';
        for (int i = n % K; i < n; ++i) {
            res += vc[i];
            if (++cnt % K == 0 && i != n - 1) { res += '-'; }
        }
        return res;
    }
};