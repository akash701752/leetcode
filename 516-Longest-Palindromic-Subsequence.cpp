class Solution {
public:
    int LPS(string a,string b)
    {
        int m , n , i , j ;
        m = n = a.length()  ;
        int dp[m+1][n+1] ;
        for(i=0;i<m+1;i++)
        {
            for(j=0;j<n+1;j++)
            {
                if(i==0 ||j==0){
                    dp[i][j] = 0 ;
                }
                else if(a[i-1]==b[j-1]){
                    dp[i][j] = 1+ dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[m][n] ;
    }
    int longestPalindromeSubseq(string s) {
        string a = s ;
        reverse(s.begin(),s.end()) ;
        return LPS(a,s) ;
    }
};
