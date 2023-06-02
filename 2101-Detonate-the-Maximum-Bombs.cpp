class Solution {
public:
    unordered_map<int,vector<int>> g;
    int temp;
    void dfs(int cur, vector<bool> &vis){
        vis[cur] = true;
        temp++;
        for(int neb : g[cur]){
            if(vis[neb]) continue;
            dfs(neb, vis);
        }
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        //making directed graph
        for(int i = 0; i<bombs.size() ; i++){
            double r = bombs[i][2] * 1.0;
            long x = bombs[i][0], y = bombs[i][1];
            for(int j = 0 ; j<bombs.size() ; j++){
                if(i == j) continue;
                long a = bombs[j][0], b = bombs[j][1];
                double dis = sqrt((x-a)*(x-a) + (y-b)*(y-b));
                if(dis <= r){
                    g[i].push_back(j);
                }
            }
        }
        int ans = 1;
        //checking for every index
        for(int i = 0 ;i<bombs.size() ; i++){
            temp = 0;
            vector<bool> vis(bombs.size(), false);
            dfs(i,vis);
            ans = max(ans, temp);
        }
        return ans;
    }
};
