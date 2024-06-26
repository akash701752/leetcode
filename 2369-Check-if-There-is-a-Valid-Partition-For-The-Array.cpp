class Solution {
    int dp[100001];
    bool check(vector<int>& nums, int i){
        if(i == nums.size())return true;
        if(dp[i] != -1)return dp[i];
        bool res1 = false,res2 = false;
        if(i < nums.size()-1 and nums[i] == nums[i+1]){
            res1 = check(nums,i+2);
            if(res1)return dp[i] = true;
        }
        if(i < nums.size()-2){
            if((nums[i] == nums[i+1] and nums[i+1] == nums[i+2]) or (nums[i] == nums[i+1]-1 and nums[i] == nums[i+2]-2)){
                res2 = check(nums,i+3);
            }
        }
        return dp[i] = res2;
        
    }
public:
    bool validPartition(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return check(nums,0);
        
    }
};
