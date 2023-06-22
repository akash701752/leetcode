class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
      int n = prices.size();
			if (n == 0) return 0;
			int dp_i0 = 0;
			int dp_i1 = INT_MIN;
			for (int i = 0; i < n; i++) {
				dp_i0 = max(dp_i0, dp_i1 + prices[i]);
				dp_i1 = max(dp_i1, dp_i0 - prices[i] - fee);
			}
			return dp_i0;
			}
};
