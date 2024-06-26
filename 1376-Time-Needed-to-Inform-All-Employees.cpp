class Solution {
public:
    int max1=0;
    map<int,vector<int>> me;
    void dfs(int n, int headID, vector<int>& manager, vector<int>& iT, int curr)        {
        max1=max(max1,curr);                                        
        for(int i=0;i<me[headID].size();i++){
            dfs(n, me[headID][i], manager, iT, curr+iT[headID]);  
        }
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& iT) {
        for(int i=0;i<n;i++){
            me[manager[i]].push_back(i);  
        }        
        dfs(n, headID, manager, iT, 0);        
        return max1;
    }
};
