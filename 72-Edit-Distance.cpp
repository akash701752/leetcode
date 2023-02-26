class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length() , n = word2.length() , i, j ;
        int dp[m+1][n+1] ;
        for(i=0;i<m+1;i++){
            dp[i][0] = i ;
        }
        for(j=0;j<n+1;j++){
            dp[0][j] = j ;
        }
        for(i=1;i<m+1;i++)
        {
           for(j=1;j<n+1;j++){
            if(word1[i-1]==word2[j-1]){
                dp[i][j] = dp[i-1][j-1] ;
            }
            else{
                dp[i][j] = 1+ min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1])) ;
            }
           }
        }
        return dp[m][n] ;
    }
};
