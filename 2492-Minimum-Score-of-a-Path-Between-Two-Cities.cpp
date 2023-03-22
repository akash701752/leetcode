class Solution {
public:
    void dfs(vector<vector<pair<int, int>>> &adj, int curr, vector<int> &vis, int &mn)
    {
        if (vis[curr]){
            return;
        }
        vis[curr] = 1;
        for (auto nxt : adj[curr]){
            mn = min(mn, nxt.second);
            dfs(adj, nxt.first, vis, mn);
        }
        return;
    }
    int minScore(int n, vector<vector<int>> &roads)
    {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (int i = 0; i < roads.size(); i++){
            adj[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        }
        int mn = INT_MAX;
        vector<int> vis(n + 1, 0);
        dfs(adj, 1, vis, mn);
        return mn;
    }
};
