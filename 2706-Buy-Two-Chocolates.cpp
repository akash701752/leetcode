class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int count = 0 , n = prices.size() ;
        int rem = money ;
        sort(prices.begin(),prices.end()) ;
        for(int i=0;i<n;i++){
            if(prices[i]<=money){
                count++;
                money -= prices[i] ;
            }
            if(count==2){
                break;
            }
        }
        if(count!=2){
            return rem;
        }
        return money;
    }
};
