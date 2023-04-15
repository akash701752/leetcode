class Solution {
public:
    int solve(int i,vector<vector<int>>& piles,int k,vector<vector<int>>&dp){
        if(i>=piles.size()){
            return 0;
        }
        if(dp[i][k]!=-1){
            return dp[i][k];
        }
        int ans = 0,sum =0;
        ans = max(ans,solve(i+1,piles,k,dp));
        for(int j=0;j<piles[i].size();j++){
            sum += piles[i][j];
            if(k-(j+1)>=0)
            ans = max(ans,sum+solve(i+1,piles,k-(j+1),dp));
        }
        return dp[i][k]=ans;
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        return solve(0,piles,k,dp);
    }
};
