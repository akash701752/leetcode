class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int i = 0, N = nums.size();
        int result=0;
        long long int element=1;
        while(element<=n){
            if(i>=N || nums[i]>element){
                result++;
                element = element*2;
            }
            else{
                element = element+nums[i];
                i++;
            }
        }
        
        return result;
    }
};
