class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size() , l , r , res = -1;
        l = 0 , r = n-1;
        while(l<=r){
            //when array is already sorted 
            if(nums[l] <= nums[r]){
                return nums[l];
            }
            int mid = l+ (r-l)/2 ;
            int next = (mid+1)%n;
            int prev = (mid+n-1)%n ;
            if(nums[mid]<=nums[next] && nums[mid]<=nums[prev]){
                res = nums[mid] ;
                break ;
            }
            else if(nums[0]<=nums[mid]){
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        return res;
    }
};
