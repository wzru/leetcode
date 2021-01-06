/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
  public:
    int calc(const string& s1, const string& s2)
    {
        int res = 0;
        for (int i = 0; i < 6; ++i) { res += (s1[i] == s2[i]); }
        return res;
    }
    void findSecretWord(vector<string>& wordlist, Master& master)
    {
        int                 l = wordlist.size();
        vector<vector<int>> sml(l, vector<int>(l));  // similarity
        vector<int>         maxs(l, 0);
        vector<bool>        vis(l, false);  // vis
        vector<vector<int>> cnt(l, vector<int>(6, 0));
        for (int i = 0; i < l; ++i) {
            for (int j = i + 1; j < l; ++j) {
                sml[i][j] = sml[j][i] = calc(wordlist[i], wordlist[j]);
                maxs[i]               = max(maxs[i], ++cnt[i][sml[i][j]]);
                maxs[j]               = max(maxs[j], ++cnt[j][sml[i][j]]);
            }
        }
        int mins = INT_MAX, mini = 0;
        for (int i = 0; i < l; ++i) {
            if (mins > maxs[i]) {
                mins = maxs[i];
                mini = i;
            }
        }
        int g = mini;
        for (int it = 0; it < 10; ++it) {
            mins    = INT_MAX;
            int res = master.guess(wordlist[g]);
            // cout<<"guess="<<wordlist[g]<<" res="<<res<<endl;
            if (res == 6) break;
            vis[g] = true;
            for (int i = 0; i < l; ++i)
                if (res != sml[g][i])
                    vis[i] = true;
                else {
                    if (!vis[i] && mins > maxs[i]) {
                        mins = maxs[i];
                        mini = i;
                    }
                }
            g = mini;
            // cout<<"g="<<g<<" mins="<<mins<<endl;
        }
    }
};