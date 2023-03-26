class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size() , i , j ;
        for(i=1;i<1001;i++){
            int count = 0;
            for(j=0;j<n;j++){
                if(nums[j] >= i){
                    count++;
                }
            }
            if(count == i){
                return count;
            }
        }
        return -1;
    }
};
