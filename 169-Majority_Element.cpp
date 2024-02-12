class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int flag = nums[0] , count = 1;
        int n = nums.size() ;
        for(int i=1;i<n;i++){
            if(flag==nums[i]){
                count++;
            }
            else if(flag!=nums[i] && flag>=1){
                count--;
                if(count==0){
                    flag = nums[i];
                    count=1;
                }
            }
            else{
                flag = nums[i];
                count = 1;
            }
        }
        return flag;
    }
    
};
