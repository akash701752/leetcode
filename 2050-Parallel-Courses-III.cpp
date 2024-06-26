class Solution {
public:
    vector<vector<int> > adj;
    vector<int> t;
    vector<int> dp;
    int dfs(int node) {
        if(dp[node]) return dp[node];
        int mx = 0;
        for(int next : adj[node]) {
            mx = max(mx, dfs(next));
        }
        return dp[node] = t[node] + mx;
    }
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        adj.resize(n);
        dp.resize(n);
        t = time;
        for(auto &r : relations) {
            adj[r[0] - 1].push_back(r[1] - 1);
        }
        int ans = 0;
        for(int i = 0; i < n; i++)
            ans = max(dfs(i), ans);
        return ans;
    }
};
