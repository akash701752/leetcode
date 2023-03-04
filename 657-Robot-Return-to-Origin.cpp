class Solution {
public:
    bool judgeCircle(string moves) {
        int  ans = 0 , l , r , u , d ;
        l = r = u = d = 0 ; 
        for(auto s : moves){
            if(s=='U'){
                u++ ;
            }
            else if(s=='D'){
                d++ ;
            }
            else if(s== 'R'){
                r++;
            }
            else{
                l++;
            }
        } 
        return abs(u-d) +abs(r-l)==0 ;
    }
};
