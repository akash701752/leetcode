class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int> > adjL;
        vector<int> indegree(n, 0);

        for(auto& edge : edges){
            int u = edge[0], v = edge[1];
            adjL[v].push_back(u);
        }

        vector<vector<int> > res(n);
        vector<int> v;
        vector<bool> vis(n);

        function<void(int)> dfs = [&](int node){
            for(auto& child : adjL[node]){
                if(vis[child]) continue;
                vis[child] = true;

                v.push_back(child);
                dfs(child);
            }
        };
        
        for(int i = 0; i < n; ++i){
            dfs(i);
            res[i] = v;
            v = vector<int>();
            vis = vector<bool>(n, false);
        }

        for(auto& arr : res){
            sort(begin(arr), end(arr));
        }

        return res;
    }
};
