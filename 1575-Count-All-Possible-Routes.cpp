const int mod = 1e9 + 7;
class Solution {
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n = locations.size();
        vector<vector<int>> mc(n, vector<int>(fuel + 1, -1));
        function<int(int, int)> dp = [&](int index, int rest) {
            if (rest < 0) return 0;
            int& v = mc[index][rest];
            if (v == -1) {
                v = index == finish;
                for (int i = 0; i < n; ++i) {
                    if (i == index) continue;
                    v += dp(i, rest - abs(locations[index] - locations[i]));
                    v %= mod;
                }
            }
            return v;
        };
        return dp(start, fuel);
    }
};
