class Solution {
public:
    bool checkOnesSegment(string s) {
        // bool ans = false ;
        // int n = s.length() , i ;
        // if(n==1){
        //     return s[0] =='1' ;
        // }
        // else if(n==2){
        //     return s[0]=='1' || s[1] =='1';
        // }
        // for(i=1;i<n;i++)
        // {
        //     if(s[i-1]=='1' && s[i] =='1'){
        //         ans = true ;
        //         break ;
        //     }
        // }
        // return ans ;
        int zero_suf = 0, one_suf = 0, i = s.size();
        if(s.size() == 1) return true;
        while(i-- > 1){
            if(s[i] == '1'){
            one_suf = 1;
            break;
            }
        }
        while(i-- > 0){
            if(s[i] == '0'){
                zero_suf = 1;
                break;
            }
        }
        if(one_suf == true && zero_suf == true)
            return false;

        return true;
    }
};
