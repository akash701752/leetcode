class Solution {
public:
    int minDelIns_Palindrome(string x,string y,int m,int n)
    {
        int t[m+1][n+1] ;
        int i , j ;
        // Initilization
        for(i=0;i<m+1;i++)
        {
            for(j=0;j<n+1;j++)
            {
                if(i==0 || j==0)
                    t[i][j] = 0 ;
            }
        }
        // DP LPS Code
        for(i=1;i<m+1;i++)
        {
            for(j=1;j<n+1;j++)
            {
                if(x[i-1]==y[j-1])
                    t[i][j] = 1+ t[i-1][j-1] ;
                else
                    t[i][j] = max( t[i-1][j] , t[i][j-1] ) ;
            }
        }
        return (m-t[m][n]) ;
    }
    int minInsertions(string s) 
    {
        string str = s ;
        reverse(str.begin(),str.end()) ;
        int n = str.length() ;
        int ans = minDelIns_Palindrome(s,str,n,n) ;
        return ans ;
    }
};
