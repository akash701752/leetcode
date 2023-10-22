class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int i=k, j=k, ans=nums[k], minv=nums[k], n=nums.size();
    
        do {
            if(i>0 && j<n-1) {
                if(nums[i-1]>=nums[j+1]){
                    i--;
                }
                else{
                    j++;
                }
            }
            else if(i==0 && j<n-1){
                j++;
            }
            else if(j==n-1 && i>0){
                i--;
            }    
            minv = min({minv,nums[i],nums[j]});
            ans = max(ans,(j-i+1)*minv);
        
        } while(i>0 || j<n-1);
        
        return ans;
    }
};
