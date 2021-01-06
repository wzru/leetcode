class Solution {
  public:
    bool is_legal(int hh, int mm)
    {
        return hh >= 0 && hh < 24 && mm >= 0 && mm < 60;
    }
    int cmp(int hh1, int mm1, int hh2, int mm2)
    {
        if (hh1 > hh2)
            return 1;
        else if (hh1 < hh2)
            return -1;
        else if (mm1 > mm2)
            return 1;
        else if (mm1 < mm2)
            return -1;
        else
            return 0;
    }
    string to_string(int hh, int mm)
    {
        string res = ::to_string(hh) + ":";
        if (hh < 10) res = "0" + res;
        if (mm < 10)
            res += "0" + ::to_string(mm);
        else
            res += ::to_string(mm);
        return res;
    }
    string nextClosestTime(string time)
    {
        vector<int> ab;
        bool        vis[10] = {0};
        for (int i = 0; i < time.size(); ++i) {
            if (isdigit(time[i]) && !vis[time[i] - '0']) {
                vis[time[i] - '0'] = true;
                ab.push_back(time[i] - '0');
                // cout<<"t="<<time[i]-'0'<<endl;
            }
        }
        int         hh0 = (time[0] - '0') * 10 + (time[1] - '0'), mm0 = (time[3] - '0') * 10 + (time[4] - '0');
        int         resh = 24, resm = 60, minh = 24, minm = 60;
        vector<int> vh, vm;
        int         n = ab.size(), found = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                for (int k = 0; k < n; ++k)
                    for (int l = 0; l < n; ++l) {
                        int hh = ab[i] * 10 + ab[j], mm = ab[k] * 10 + ab[l];
                        if (is_legal(hh, mm)) {
                            if (cmp(hh, mm, minh, minm) == -1) { minh = hh, minm = mm; }
                            if (cmp(hh, mm, hh0, mm0) == 1) {
                                found = 1;
                                if (cmp(hh, mm, resh, resm) == -1) { resh = hh, resm = mm; }
                            }
                        }
                    }
        if (found)
            return to_string(resh, resm);
        else
            return to_string(minh, minm);
    }
};