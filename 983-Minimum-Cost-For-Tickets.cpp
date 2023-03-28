class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size() , i ;
        vector<int> dp(n+1,365*costs[0]) ;
        dp[n] = 0 ;
        for(i=n-1;i>=0;i--){
            int weekly = i , monthly = i ;
            while(weekly<n && days[weekly] < days[i]+7){
                weekly++;
            }
            while(monthly<n && days[monthly]< days[i]+ 30){
                monthly++;
            }
            dp[i] = min({costs[0]+dp[i+1], costs[1]+dp[weekly], costs[2]+dp[monthly]});
        }
        return dp[0] ;
    }
};
