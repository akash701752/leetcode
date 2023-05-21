class Solution {
    int r,c;
    int ans=INT_MAX;
    
    void dfs(vector<vector<int>>& A,int i,int j,vector<vector<bool>>& vis,vector<pair<int,int>>& S)
    {
        if(i<0||j<0||i>=r||j>=c) return;
        if(vis[i][j]||A[i][j]==0) return;
        
        vis[i][j]=true; 
        S.push_back(make_pair(i,j));
        dfs(A,i-1,j,vis,S);
        dfs(A,i+1,j,vis,S);
        dfs(A,i,j-1,vis,S);
        dfs(A,i,j+1,vis,S);
        
        return;
    }
public:
    int shortestBridge(vector<vector<int>>& A) {
        
        r=A.size(); c=A[0].size();
        vector<pair<int,int>> P,Q;
        vector<vector<bool>> vis(r,vector<bool>(c,false));
        int flag=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(A[i][j]==1&&!vis[i][j]){
                    if(flag==0) {dfs(A,i,j,vis,P); flag++;}
                    else {dfs(A,i,j,vis,Q);}
                    
                }
            }
        }
        
        int ans=INT_MAX;
        
        for(int i=0;i<P.size();i++){
            for(int j=0;j<Q.size();j++){
                int x1=P[i].first;
                int x2=Q[j].first;
                int y1=P[i].second;
                int y2=Q[j].second;
                
                int dis=abs(x1-x2)+abs(y1-y2);
                
                ans=min(ans,dis);
            }
        }
        return ans-1;
    }
};
