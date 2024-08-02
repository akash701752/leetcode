class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int one = count(nums.begin(), nums.end(), 1); 
        int zero = 0;
       for(int i=0;i<one;i++){
        if(nums[i]==0)
            zero++;
       }


        int ans = INT_MAX;
        ans =min(zero, ans);
        for(int i=one;i<2*n;i++){
            if(nums[i%n] == 0)
                zero++;
            if(nums[(i-one)%n]==0)
                zero--;
            ans=min(ans,zero);
        }

        return ans;

    }
};
