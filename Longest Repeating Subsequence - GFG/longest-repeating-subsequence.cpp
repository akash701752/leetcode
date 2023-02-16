//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	    int LPS(string &a,string &b)
	    {
	        int m , n ,i , j ;
            m = n = a.length() ;
            vector<vector<int> > dp(m+1,vector<int>(n+1)) ;
            for(i=0;i<m+1;i++)
            {
                for(j=0;j<n+1;j++)
                {
                    if(i==0 || j==0){
                        dp[i][j] = 0;
                    }
                    else if(a[i-1]==b[j-1] && i!=j){
                        dp[i][j] = 1+ dp[i-1][j-1] ;
                    }
                    else{
                        dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                    }
                }
            }
            return dp[m][n] ;
	    }

		int LongestRepeatingSubsequence(string str){
		    // Code here
		    return LPS(str,str) ;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends