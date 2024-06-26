class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size(),mid=n/2,ans=0,j=1;
        
        for(int i=mid;i<n;i++,j=j+2){
            ans = max(ans ,nums[i]+nums[i-j]);
        }
        return ans;
    }
};
