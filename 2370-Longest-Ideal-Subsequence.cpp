class Solution {
public:
    
    int solve(int n,string &s,int k,int prev,vector<vector<int>> &dp){
        if(n>=s.size()) return 0;
        if(dp[n][prev]!=-1) {
            return dp[n][prev];

        }
        int pick=0;
        
        if(prev==0 or int(abs(s[n]-prev))<=k ){
            pick=1+solve(n+1,s,k,s[n],dp);
        }
        
        int notpick=0+solve(n+1,s,k,prev,dp);
        
        return dp[n][prev]= max(pick,notpick);
    }
    int longestIdealString(string s, int k) {
        vector<vector<int>> dp(s.size()+1,vector<int>(150,-1));
        
        return solve(0,s,k,0,dp);

    }
};
