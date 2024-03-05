class Solution {
public:
    int minimumLength(string s) {
        int n = s.length() ;

        int i= 0 , j = n-1;

        while(i<j)
        {
            char ch = s[i] ;
            if(ch!= s[j]){
                break;
            }
            while(i<=j && ch==s[i]){
                i++ ;
            }
            while(j>i  && s[j]==ch){
                j-- ;
            }
        }
        int ans = (j-i+1) ;
        if(ans<0){
            return 0 ;
        }
        return ans ;
    }
};
