class Solution {
public:
    int dp[101][101]={};
    vector<int> cut;
    int fun(int l,int r,int dl,int dr)
    {
        if(dr<dl)
            return 0;
        if(dp[dl][dr])
            return dp[dl][dr];
        
        int ans=INT_MAX;
        for(int i=dl;i<=dr;i++)
            ans=min(ans,fun(l,cut[i],dl,i-1)+fun(cut[i],r,i+1,dr)+(r-l));
        
        return dp[dl][dr]=ans;
    }
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        cut=cuts;
        return fun(0,n,0,cuts.size()-1);
        
    }
};
