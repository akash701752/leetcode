class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> mc(n + 1, vector<int>(2, 0));
        int res = 0;
        for (int i = 1; i<= n; ++i) {
            if (nums[i - 1] == 1) {
                mc[i][0] = mc[i - 1][0] + 1;
                mc[i][1] = mc[i - 1][1] + 1;
            } else {
                mc[i][0] = 0;
                mc[i][1] = mc[i - 1][0] + 1;
            }
            res = max(res, max(mc[i][0], mc[i][1]));
        }
        return res - 1;
    }
};
