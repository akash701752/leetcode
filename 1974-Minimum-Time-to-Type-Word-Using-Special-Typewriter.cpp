class Solution {
public:
    int minTimeToType(string word) {
        int time = 0 , curr = 0 ;
        for(auto s : word){
            int ind = s -'a' ;
            int curr_prev = abs(curr-ind) ;
            int prev_curr = 26 - abs(curr-ind) ;
            time += min(curr_prev,prev_curr) ;
            time++ ;
            curr = ind ;
        }
        return time ;
    }
};
