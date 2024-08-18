class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n) ;
        dp[0] = 1;
        int two = 0 , three= 0 , five = 0 , i;
        for(i=1;i<n;i++)
        {
            int twoMultiple   = dp[two]*2 ;
            int threeMultiple = dp[three]*3 ;
            int fiveMultiple  = dp[five]*5 ;

            dp[i] = min(twoMultiple,min(threeMultiple,fiveMultiple)) ;

            if(dp[i]==twoMultiple){
                two++ ;
            }
            if(dp[i]==threeMultiple){
                three++ ;
            }
            if(dp[i]==fiveMultiple){
                five++ ;
            }
        }
        return dp[n-1] ;
    }
};
