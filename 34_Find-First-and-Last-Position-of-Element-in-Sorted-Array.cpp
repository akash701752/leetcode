class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0 , n = nums.size() , r , res = -1;
        r = n-1;
        vector<int> v(2,-1);
        while(l<=r){
            int mid = l+ (r-l)/2 ;
            if(nums[mid]==target){
                res= mid ;
                r = mid-1;
            }
            else if(nums[mid]>target){
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        v[0] = res;
        l = res , r = res+1;
        while(r<n && l!=-1){
            if(nums[l]!=nums[r]){
                break;
            }
            r++;
        }
        v[1]= r-1 ;
        return v;
    }
};
