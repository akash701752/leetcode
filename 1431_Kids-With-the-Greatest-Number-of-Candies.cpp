class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int mx = -1 , i , n = candies.size() ;
        for(i=0;i<n;i++){
            mx = max(mx,candies[i]) ;
        }
        vector<bool> res(n) ;
        for(i=0;i<n;i++){
            if(candies[i]+extraCandies>=mx){
                res[i] = true ;
            }
            else{
                res[i] = false ;
            }
        }
        return res ;
    }
};
