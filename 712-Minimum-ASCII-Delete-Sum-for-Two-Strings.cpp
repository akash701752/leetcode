class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size(), m = s2.size(), i, j;
        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
        for(i = 1; i <= n; i++){
            dp[i][0] = dp[i-1][0] + s1[i-1];
        }
        for(j = 1; j <= m; j++){
            dp[0][j] = dp[0][j-1] + s2[j-1];
        }
        for(i = 1; i <= n; i++){
            for(j = 1; j <= m; j++){
                if(s1[i-1] != s2[j-1]){
                    int x = s1[i-1] + dp[i-1][j];//deleting s1[i-1]th char + minimumDeleteSum(s1 till length i-2 and s2 till j)
                    int y = s2[j-1] + dp[i][j-1];//deleting s2[j-1]th char + minimumDeleteSum(s2 till length j-2 and s1 till i)
                    dp[i][j] = min(x,y);
                }else{
                    dp[i][j] = dp[i-1][j-1];
                }
            }
        }
        return dp[n][m];
    }
};
