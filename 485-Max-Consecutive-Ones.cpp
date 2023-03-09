class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) 
    {
        int n= nums.size() , i , count = 0 , mx = 0;
        for(i=0;i<n;i++){
            if(nums[i]==1){
                count++;
                mx = max(mx,count) ;
            }
            else{
                count = 0 ;
            }
        }
        return mx ;
    }
};
