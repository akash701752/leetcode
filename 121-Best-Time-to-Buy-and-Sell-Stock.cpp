class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX , profit = 0 ;
        for(auto p : prices)
        {
            minPrice = min(minPrice,p) ;
            profit = max(profit,p-minPrice) ;
        }
        return profit ;
    }
};
