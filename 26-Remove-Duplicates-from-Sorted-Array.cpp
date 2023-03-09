class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int n = nums.size(), i , ind = 1 ; 
        for(i=1;i<n;i++){
            if(nums[ind-1]==nums[i]){
                continue;
            }
            else{
                nums[ind++] = nums[i] ;
            }
        }
        return ind ;
    }
};
