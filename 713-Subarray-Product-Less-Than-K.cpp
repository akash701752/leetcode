class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int l=0;
        int p=1;
        int res=0;
        if(k<=1){
            return 0;
        }
        for(int r=0;r<nums.size();r++){
            p=p*nums[r];
            while(p>=k){
                p=p/nums[l];
                l++;
            }
            res+=(r-l+1);
        }
        return res;
    }
};
