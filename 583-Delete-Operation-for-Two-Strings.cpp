class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length() , n = word2.length() , i , j ;
        int dp[m+1][n+1] ;
        for(i=0;i<m+1;i++)
        {
            for(j=0;j<n+1;j++)
            {
                if(i==0 || j==0){
                    dp[i][j] = 0 ;
                }
                else if(word1[i-1]==word2[j-1]){
                    dp[i][j] = 1+ dp[i-1][j-1] ;
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]) ;
                }
            }
        }
        return m- dp[m][n] + n- dp[m][n] ;
    }
};
