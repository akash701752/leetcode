class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans=1;
        int m=*max_element(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            int c=0;
            while(i<nums.size() && nums[i]==m){
                c++;
                i++;                
            }
            ans=max(c,ans);
        }
        return ans;
    }
};
