class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int i=0,j=0,cnt=nums[0]&1,n=nums.size(),ans=0;
        while(j<n){
            if(cnt>k){
                if(nums[i]&1)cnt--;
                i++;
            }
            else if(cnt<k){
                j++;
                if(nums[j]&1)cnt++;
            }
            else{
                ans++;
                int l=i;
                while(!(nums[l]&1)){
                    l++;
                    ans++;
                }
                j++;
                if(j<n && nums[j]&1)cnt++;
            }
        }
        return ans;
    }
};
