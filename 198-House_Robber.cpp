class Solution {
public:
    int solve(vector<int>& nums,vector<int>& dp,int i){
        if(i>=nums.size()){
            return 0 ;
        }
        if(dp[i]!=-1){
            return dp[i] ;
        }
        int rob = solve(nums,dp,i+2) + nums[i] ;
        int not_rob = solve(nums,dp,i+1) + 0 ;
        dp[i] = max(rob,not_rob) ;
        return dp[i] ;
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+1,-1) ;
        return solve(nums,dp,0) ;
    }
};
