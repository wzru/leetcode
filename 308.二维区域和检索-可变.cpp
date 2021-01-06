class NumMatrix {
  public:
    int                 n = 0, m = 0;
    vector<vector<int>> C, M;
    inline int          lowbit(int x)
    {
        return x & (-x);
    }
    NumMatrix(vector<vector<int>>& matrix) : M(matrix)
    {
        n = matrix.size();
        if (n) m = matrix[0].size();
        C = vector<vector<int>>(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) { add(i + 1, j + 1, M[i][j]); }
        }
    }
    void add(int i, int j, int v)
    {
        for (int x = i; x <= n; x += lowbit(x)) {
            for (int y = j; y <= m; y += lowbit(y)) { C[x][y] += v; }
        }
    }
    int get_sum(int i, int j)
    {
        int sum = 0;
        for (int x = i; x; x -= lowbit(x)) {
            for (int y = j; y; y -= lowbit(y)) { sum += C[x][y]; }
        }
        return sum;
    }
    void update(int x, int y, int v)
    {
        add(x + 1, y + 1, v - M[x][y]);
        M[x][y] = v;
    }
    int sumRegion(int x1, int y1, int x2, int y2)
    {
        return get_sum(x2 + 1, y2 + 1) - get_sum(x1, y2 + 1) - get_sum(x2 + 1, y1) + get_sum(x1, y1);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(m);
 * obj->update(row,col,val);
 * int param_2 = obj->sumRegion(row1,col1,row2,col2);
 */