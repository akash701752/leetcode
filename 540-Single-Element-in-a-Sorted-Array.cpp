class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int  n = nums.size() ;
        int high = n-1 , low = 0 ;
        if(high==0){
            return nums[0] ;
        }
        else if(nums[0]!=nums[1]){
            return nums[0] ;
        }
        else if(nums[high-1]!=nums[high]){
            return nums[high] ;
        }
        while(low<=high)
        {
            int mid = low+ (high-low)/2 ;
            if(nums[mid-1]!=nums[mid] && nums[mid+1]!=nums[mid]){
                return nums[mid] ;
            }
            else if( (mid%2==0 && nums[mid]==nums[mid+1]) || (mid%2==1 && nums[mid-1]==nums[mid]) ){
                low = mid+1 ;
            }
            else{
                high = mid-1;
            }
        }
        return -1;
    }
};
