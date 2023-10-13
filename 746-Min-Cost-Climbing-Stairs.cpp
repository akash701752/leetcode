class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size() ;
        int take = 0 , not_take = 0 ;
        for(int i=0;i<n;i++){
            int new_take = cost[i] + min(take,not_take) ;
            not_take = take ;
            take = new_take;
        }
        return min(take,not_take) ;
    }
};
