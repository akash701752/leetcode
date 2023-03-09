class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size() , sum = 0, i ;
        sum = (n*(n+1))/2 ;
        for(i=0;i<n;i++){
            sum -= nums[i] ;
        }
        return sum ;
    }
};
