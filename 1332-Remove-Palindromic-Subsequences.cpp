class Solution {
public:
    int removePalindromeSub(string s) {
        int ans = 1  , i , j , n = s.length() ;
        i = 0 , j = n-1 ;
        while(i<j){
            if(s[i]!=s[j]){
                ans = 2 ;
                break ;
            }
            i++;
            j--;
        }
        return ans ;
    }
};
