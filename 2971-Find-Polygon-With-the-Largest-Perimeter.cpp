class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        long long sum=0;
        for(auto &i : nums){
            sum +=i;
        }
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i=n-1 ; i>=0 ; --i) {
            if(sum-nums[i]>nums[i]) {
                return sum;
            }
            sum -=nums[i];
        }
        return -1;
    }
};
