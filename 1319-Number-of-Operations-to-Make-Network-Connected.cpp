class Solution {
public:
    void connComponents(int i,unordered_map<int,vector<int>> &mp,vector<bool> &vis){
        vis[i] = true ;
        for(auto g: mp[i]){
            if(!vis[g]){
                connComponents(g,mp,vis) ;
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int size = connections.size() ;
        if(size<n-1){
            return -1;
        }
        unordered_map<int,vector<int>> mp ;
        for(auto num: connections){
            mp[num[0]].push_back(num[1]);
            mp[num[1]].push_back(num[0]);
        }
        vector<bool> vis(n,false) ;
        int connected = 0 , i ;
        for(i=0;i<n;i++){
            if(vis[i]==false){
                connComponents(i,mp,vis) ;
                connected++;
            }
        }
        return connected-1 ;
    }
};
