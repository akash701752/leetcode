class Solution {
public:
    int numSub(string s) {
        int n = s.length() , ans = 0 , count = 0 ,  mod = 1e9+7 , i ;
        for(i=0;i<n;i++){
            if(s[i]=='1'){
                count++;
            }
            else{
                count = 0 ;
            }
            ans = (ans+count)%mod ;
            // ans += count ;
        }
        return ans%mod ;
    }
};
