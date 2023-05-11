class Solution {
public:
    int LCS(vector<int> &nums1, vector<int> &nums2, int i, int j, vector<vector<int>> &dp) {
        if(i == nums1.size() || j == nums2.size())
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int res = 0;
        if(nums1[i] == nums2[j]) {
            res = 1+LCS(nums1, nums2, i+1, j+1, dp);
        } 
        else{
            res = max(LCS(nums1, nums2, i+1, j, dp), LCS(nums1, nums2, i, j+1, dp));
        }
        dp[i][j] = res;
        return res;
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size(), vector<int>(nums2.size(), -1));
        return LCS(nums1, nums2, 0, 0, dp);
    }
};
