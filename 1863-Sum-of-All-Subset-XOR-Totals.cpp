class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        
        int run = pow(2, n);
        int ans = 0;
        for(int i=0; i<run; i++){
            int res = 0;
            for(int j=0; j<n; j++){
                if(i & (1<<j)) res ^= nums[j];
            }
            
            ans += res;
        }
        
        return ans;
    }
};
