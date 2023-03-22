class Solution {
public:
    int countElements(vector<int>& nums) {
        sort(nums.begin(),nums.end()) ;
        int count = 0 , i ,  n = nums.size();
        for(i=1;i<n-1;i++){
            if(nums[i]>nums[0] && nums[i]<nums[n-1]){
                count++ ;
            }
        }
        return count ;
    }
};
