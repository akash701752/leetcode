class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        vector<int> ans(nums.size(), 0);
        int n = nums.size();
        for(int i=1; i<n; i++){
            ans[0] += (nums[i]-nums[0]);
        }
        for(int i=1; i<n; i++){
            ans[i] = ans[i-1] + (2*i-n)*(nums[i]-nums[i-1]);
        }
        return ans; 
    }
};
