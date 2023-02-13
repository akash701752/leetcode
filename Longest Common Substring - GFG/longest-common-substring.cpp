//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    
    int longestCommonSubstr (string S1, string S2, int m, int n)
    {
        // your code here
        int dp[m+1][n+1] , i, j , ans = INT_MIN;
        for(i=0;i<m+1;i++)
        {
            for(j=0;j<n+1;j++)
            {
                if(i==0 || j==0){
                    dp[i][j] = 0 ;
                }
                else if(S1[i-1]==S2[j-1]){
                    dp[i][j] = 1+ dp[i-1][j-1] ;
                }
                else{
                    dp[i][j] = 0 ;
                }
                if(dp[i][j]>ans){
                    ans = dp[i][j] ;
                }
            }
        }
        return ans ;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends