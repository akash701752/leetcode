class Solution {
public:
    int balancedStringSplit(string s) {
        int l = 0 , count = 0 ;
        for(auto it : s){
            if(it=='L'){
                l++ ;
            }
            if(it=='R'){
                l-- ;
            }
            if(l==0){
                count++ ;
            }
        }
        return count ;
    }
};
