class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int i , n = nums.size() ;
        vector<int> ans ;
        for(i=0;i<n;i++){
            ans.push_back(nums[nums[i]]);
        }
        return ans;
    }
};
