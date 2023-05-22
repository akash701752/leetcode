class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int minStart = 1 , i , n = nums.size() , sum = 0 ;
        for(i=0;i<n;i++){
            sum += nums[i] ;
            if(nums[i]<0 && sum<1){
                minStart = max(1-sum,minStart) ; // 1-sum if because to make it positive
            }
        }
        return minStart ;
    }
};
