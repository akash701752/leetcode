class Solution {
public:
    int maxScore(vector<int>& nums) {
        int n = nums.size();
        int m = (1 << n) + 1;
        vector<vector<int>> dp(n, vector<int>(m, 0));
        return recur(nums, 1, 0, n, dp);
    }
    
    int gcd(int x, int y){
        if(y == 0) return x;
        return gcd(y, x % y);
    }
    
    int recur(vector<int>& nums, int op, int mask, int& n, vector<vector<int>>& dp){
        if(op > n / 2){
            return 0;
        }
        if(dp[op][mask] != 0) return dp[op][mask];
        for(int i=0; i<n; i++){
            if((mask >> i) & 1) continue;
            for(int j=i+1; j<n; j++){
                if((mask >> j) & 1) continue;
                int n_mask = (1 << i) | (1 << j) | mask;
                int score = op * gcd(nums[i], nums[j]) + recur(nums, op+1, n_mask, n, dp);
                dp[op][mask] = max(dp[op][mask], score);
            }
        }
        return dp[op][mask];
    }
};
