//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int LPS(string a,string b)
    {
        int m , n , i , j ;
        m = n = a.length() ;
        vector<vector<int> >dp(m+1,vector<int>(n+1)) ;
        for(i=0;i<m+1;i++)
        {
            for(j=0;j<n+1;j++)
            {
                if(i==0 ||j==0){
                    dp[i][j] = 0 ;
                }
                else if(a[i-1]==b[j-1]){
                    dp[i][j] = 1+ dp[i-1][j-1] ;
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]) ;
                }
            }
        }
        return dp[m][n] ;

    }
    int longestPalinSubseq(string A) {
        //code here
        string a = A ;
        reverse(A.begin(),A.end()) ;
        return LPS(a,A) ;
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends