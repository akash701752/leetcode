class Solution {
public:
    int strangePrinter(string s) {
        int i,j,n=s.length();
		// if empty string
        if(n==0)
            return 0;
        
		// removing multiple consecutive elements only to 1 occurence 
        string t=s.substr(0,1);
        char prev=t[0];
        
        for(i=1;i<n;i++){
            if(s[i]!=prev){
                prev=s[i];
                t=t+prev;
            }
        }
        n=t.length();
		// base cases
        if(n==1)
            return 1;
        if(n==2)
            return 2;
        
        int dp[n][n];
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                dp[i][j]=INT_MAX;//initialized
				
		// for substrings of length < 3 since we have removed multiple consecutive occurences of each character
        for(i=0;i<n-1;i++){
            dp[i][i]=1;
            dp[i][i+1]=2;
        }
        dp[n-1][n-1]=1;
        
		for(i=2;i<n;i++)
            for(j=0;j<n;j++){
                if(j+i>=n)
                    break;
                int mn=INT_MAX;
				
				// simple condition 
                dp[j][i+j]=1+min(dp[j+1][i+j],dp[j][i+j-1]);
				
                // if 1st and last char of substring are same then 1st occurence or last occurence can be managed at same time
				if(t[j]==t[i+j])
                    dp[j][i+j]=min(dp[j][i+j-1],dp[j+1][i+j]);
                
				// breaking into parts
                for(int k=j;k<i+j;k++){
                    int l=dp[j][k],r=dp[k+1][i+j];
                    if(k>j&&t[k]==t[j])
                        l=min(dp[j][k-1],dp[j+1][k]);
                    if(t[k+1]==t[j+i]&&k+1<i+j)
                        r=min(dp[k+2][i+j],dp[k+1][i+j]);
                    dp[j][i+j]=min(dp[j][i+j],l+r);
                }
            }
        
        return dp[0][n-1];
    }
};
