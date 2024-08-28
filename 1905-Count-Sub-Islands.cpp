class Solution {
public:
    void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j, int& cnt, int& match) {
        if (i < 0 || i >= grid1.size() || j < 0 || j >= grid1[0].size() || grid2[i][j] != 1) {
            return;
        }
        if (grid1[i][j] == grid2[i][j]) {
            match++;
        }
        cnt++;
        grid2[i][j] = 0;
        dfs(grid1, grid2, i + 1, j, cnt, match);
        dfs(grid1, grid2, i - 1, j, cnt, match);
        dfs(grid1, grid2, i, j + 1, cnt, match);
        dfs(grid1, grid2, i, j - 1, cnt, match);
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int ans = 0;
        for (int i = 0; i < grid2.size(); i++) {
            for (int j = 0; j < grid2[0].size(); j++) {
                if (grid2[i][j] == 1) {
                    int match = 0;
                    int cnt = 0;
                    dfs(grid1, grid2, i, j, cnt, match);
                    if (cnt == match) {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};
