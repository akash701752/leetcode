class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int count = 0 , i , j , n = nums.size();
        for(i=0;i<n-1;i++){
            for(j=i+1;j<n;j++){
                if(nums[i]==nums[j]){
                    count++;
                }
            }
        }
        return count ;
    }
};
