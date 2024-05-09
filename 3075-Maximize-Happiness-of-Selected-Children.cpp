class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long ans = 0;
        int n = happiness.size();
        int i = n - 1;
        sort(happiness.begin(), happiness.end());
        
        int diff = 0;
        while(k--){
            if(happiness[i] + diff < 0){
                ans += 0;
            }
            else{
                ans += happiness[i] + diff;
            }
            i--;
            diff -= 1;
        }
        
        return ans;
    }
};
