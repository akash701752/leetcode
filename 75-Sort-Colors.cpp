class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size()  , low, mid , high ;
        low = mid = 0 ;
        high = n-1;
        while(mid<=high)
        {
            if(nums[mid]==0){
                swap(nums[mid],nums[low]) ;
                low++;
                mid++;
            }
            else if(nums[mid]==1){
                mid++;
            }
            else if(nums[mid]==2){
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }
};
