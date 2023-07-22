class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        vector<pair<int,int>> const c_moves = {{2, 1}, {2, -1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {1, -2}, {-1, -2}};
        vector<double> v(N * N);
        v[N * r + c] = 1;
        for (int istep = 0; istep < K; ++istep) {
            vector<double> vn(N * N);
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    if (v[N * i + j] != 0) {
                        for (auto& pm: c_moves) {
                            int in = i + pm.first, jn = j + pm.second;
                            if (in >= 0 && in < N && jn >= 0 && jn < N)
                                vn[N * in + jn] += v[N * i + j];
                        }
                    }
                }
            }
            v = vn;
        }
        return accumulate(v.begin(), v.end(), 0.0, plus<double>()) / pow(8, K);
    }
};
