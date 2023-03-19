class Solution {
public:
    int binarySearch(vector<int> &nums, int key){
        int low, high , res = -1 , n = nums.size() ;
        low = 0 , high = n-1 ;
        while(low<=high)
        {
            int mid = low+ (high-low)/2 ;
            if(nums[mid]==key){
                res = mid ;
                high = mid-1;
            }
            else if(nums[mid]>key){
                high = mid-1;
            }
            else{
                low = mid+1 ;
            }
        }
        return res ; 
    }
    vector<int> targetIndices(vector<int>& nums, int target) {
        int  n = nums.size() ;
        sort(nums.begin(),nums.end()) ;
        vector<int> ans ;
        if(n==1){
            if(nums[0]==target){
                ans.push_back(0) ;
                return ans ;
            }
            else{
                return ans ;
            }
        }
        int ind = binarySearch(nums,target) ;
        if(ind!=-1){
            int i = ind ;
            while(nums[i]==nums[ind] && i<n ){
                ans.push_back(i) ;
                i++ ;
            }
            return ans ;
        }
        else{
            return ans ;
        }
    }
};
