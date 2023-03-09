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
        l = 0 , r = n-1;
        while(l<=r){
            int mid = l+ (r-l)/2;
            if(nums[mid]==target){
                res= mid;
                l = mid+1;
            }
            else if(nums[mid]>target){
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        v[1]= res ;
        return v;
    }
};
