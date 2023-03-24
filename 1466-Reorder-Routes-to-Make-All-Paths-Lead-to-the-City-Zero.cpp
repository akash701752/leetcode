class Solution {
public:
    int ans=0;
    vector<pair<int,int>> adj[50005];
    int vis[50005];
    void dfs(int c){
        vis[c]=1; 
        for(auto p:adj[c]){
            if(!vis[p.first]){
                ans+=p.second;
                dfs(p.first);
            }
        }
        
    } 
    int minReorder(int n, vector<vector<int>>& connections) {
        for(int i=0;i<connections.size();i++){
            adj[connections[i][0]].push_back({connections[i][1],1});
            adj[connections[i][1]].push_back({connections[i][0],0});
        }
        dfs(0); 
        return ans;   
    }
};
