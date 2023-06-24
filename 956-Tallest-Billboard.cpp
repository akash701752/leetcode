class Solution {
public:
    int dp[1001][10001];
    int helper(int i, int n, int d, vector<int>&rods){
        if(i==n){
            if(d==0){
                return 0;
            }
            return INT_MIN;
        }
        if(dp[i][5000+d]!=-1){
            return dp[i][5000+d];
        }
        int notpick=helper(i+1,n,d,rods);
        int pick1=rods[i]+helper(i+1,n,d+rods[i],rods);
        int pick2=helper(i+1,n,d-rods[i],rods);
        return dp[i][5000+d]=max({notpick,pick1,pick2});
    }
    int tallestBillboard(vector<int>& rods) {
        int n=rods.size();
        memset(dp,-1,sizeof(dp));
        return helper(0,n,0,rods);
    }
};
