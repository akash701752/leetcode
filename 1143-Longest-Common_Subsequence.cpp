class Solution {
public:
    // int solve(string text1, string text2,int m,int n,vector<vector<int>> &dp){
    //     if(m==0 || n==0){
    //         return 0 ;
    //     }
    //     if(dp[m][n]!=-1){
    //         return dp[m][n] ;
    //     }
    //     if(text1[m-1]==text2[n-1]){
    //         return dp[m][n] = 1+ solve(text1,text2,m-1,n-1,dp);
    //     }
    //     else{
    //         return dp[m][n] =max(solve(text1,text2,m-1,n,dp),solve(text1,text2,m,n-1,dp));
    //     }
    // }
    int longestCommonSubsequence(string text1, string text2) 
    {
        int m = text1.length() ;
        int n = text2.length() ;
        //vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        //return solve(text1,text2,m,n,dp);
        int dp[m+1][n+1] ;
        for(int i=0;i<m+1;i++){
            for(int j=0;j<n+1;j++){
                if(i==0 || j==0){
                    dp[i][j] = 0 ;
                }
                else{
                    if(text1[i-1]==text2[j-1]){
                        dp[i][j] = 1+ dp[i-1][j-1] ;
                    }
                    else{
                        dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                    }
                }
            }
        }
        return dp[m][n] ;
    }
};
