class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size() , n = matrix[0].size() ;
        int dp[m+1][n+1] , i , j ;
        int ans = 0 ;
        for(i=0;i<m+1;i++){
            dp[i][0] =0;
        }
        for(j=0;j<n+1;j++){
            dp[0][j] = 0;
        }
        for(i=1;i<m+1;i++)
        {
            for(j=1;j<n+1;j++)
            {
                if(matrix[i-1][j-1]=='1'){
                    dp[i][j] = 1+ min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1])) ;
                }
                else{
                    dp[i][j] = 0 ;
                }
                ans = max(ans,dp[i][j]) ;
            }
        }
        return ans*ans;
    }
};
