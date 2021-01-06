class Solution {
  public:
    struct Segment
    {
        int l, r;
        Segment(int l = 0, int r = 0) : l(l), r(r) {}
        bool in(int x)
        {
            return x >= l && x <= r;
        }
    };
    int binary_search(vector<Segment>& segs, int x)
    {
        int l = 0, r = segs.size() - 1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (segs[mid].in(x))
                return mid;
            else if (segs[mid].l > x)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return -1;
    }
    int kEmptySlots(vector<int>& bulbs, int k)
    {
        int             n = bulbs.size();
        vector<Segment> segs{Segment(1, n)};
        for (int i = 0; i < n; ++i) {
            int pos = binary_search(segs, bulbs[i]);
            if ((bulbs[i] - segs[pos].l == k && segs[pos].l != 1) || (segs[pos].r - bulbs[i] == k && segs[pos].r != n))
                return i + 1;
            else {
                Segment tmp = segs[pos];
                segs.erase(segs.begin() + pos);
                if (bulbs[i] != tmp.r) segs.insert(segs.begin() + pos, Segment(bulbs[i] + 1, tmp.r));
                if (bulbs[i] != tmp.l) segs.insert(segs.begin() + pos, Segment(tmp.l, bulbs[i] - 1));
            }
        }
        return -1;
    }
};