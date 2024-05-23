class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        int full_set = (1<<n)-1;
        int count = 0;
        vector<bool> values_to_avoid(1001, false);
        for(int j = 1; j<=full_set; ++j) {
            int x = j;
            std::fill(values_to_avoid.begin(), values_to_avoid.end(), false);
            int i = 0;
            while(x) {
                if(x%2==1) {
                    int val = nums[i];
                    if(values_to_avoid[val]) {
                        break;
                    }
                    if(val+k <= 1000) {
                        values_to_avoid[val+k] = true;
                    }
                    if(val-k >= 0) {
                        values_to_avoid[val-k] = true;
                    }
                }
                x/=2;
                ++i;
            }
            if(x == 0) count++;
        }
        
        return count;
    }
};
