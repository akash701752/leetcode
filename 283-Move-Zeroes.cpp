class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size() , i , ind = 0 ;
        for(i=0;i<n;i++){
            if(nums[i]==0){
                continue;
            }
            else{
                nums[ind++] = nums[i] ;
            }
        }
        for(i=ind;i<n;i++){
            nums[i] = 0 ;
        }
    }
};
