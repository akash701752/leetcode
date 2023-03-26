class Solution {
public:
    int detectCycle(int sv,vector<vector<int>> &graph,vector<bool> &vis,set<int> &st){
        vis[sv] = true ;
        st.insert(sv) ;
        for(int i=0;i<graph[sv].size();i++)
        {
            if(st.find(graph[sv][i])!=st.end()){
                return sv ;
            }
            if(vis[graph[sv][i]]==false){
                int s = detectCycle(graph[sv][i],graph,vis,st) ;
                if(s!=-1){
                    return s ;
                }
            }
        }
        st.erase(sv) ;
        return -1 ;
    }
    int longestCycle(vector<int>& edges) {
        int n = edges.size() , i ;
        vector<vector<int>> graph(n) ;
        for(i=0;i<n;i++){
            if(edges[i]!=-1){
                graph[edges[i]].push_back(i) ;
            }
        }
        vector<bool> vis(n,false) ;
        int ans = -1 ;
        for(i=0;i<n;i++)
        {
            if(vis[i]==false)
            {
                set<int> st ;
                int isCycle = detectCycle(i,graph,vis,st) ;
                if(isCycle>-1){
                    int count = 1 ;
                    int sv = i ;
                    while(edges[sv]!=i){
                        sv = edges[sv] ;
                        count ++ ;
                    }
                    ans = max(ans,count) ;
                }
            }
        }
        return ans ;
    }
};
