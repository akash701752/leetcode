class Solution {
public:
    void dfs(vector<int>adj[],int i,vector<int>&vis,set<int>&st){
        vis[i] = 1;
        for(auto x:adj[i]){
            if(!vis[x]){
                st.insert(x);
                dfs(adj,x,vis,st);
            }
        }
        return;
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        for(auto x:edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        vector<long long>v;
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                set<int>st;
                st.insert(i);
                dfs(adj,i,vis,st);
                v.push_back(st.size());
            }
        }
        long long c = 0;
        long long k = n;
        for(int i=0;i<v.size();i++){
            k-=v[i];
            c+=(v[i]*k);
        }
        return c;
    }
};
