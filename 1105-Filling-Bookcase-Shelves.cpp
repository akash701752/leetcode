class Solution {
public:
    int minHeightShelves(vector<vector<int>>& a, int shelfWidth) {
        int n = a.size();
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < n; i++){
            int temp = 0, curr_w= 0;
            for (int j = i; j >= 0; j--){
                int w = a[j][0] , h = a[j][1];
                if (curr_w+w > shelfWidth){
                    break;
                } 
                curr_w += w;
                temp = max(temp,h);
                dp[i+1] = min(dp[j]+temp, dp[i+1]);
            }
            curr_w = 0;
            temp = 0;
        }
        return dp.back();
    }
};
