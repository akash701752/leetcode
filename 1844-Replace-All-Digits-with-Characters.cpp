class Solution {
public:
    char shift(char ch,int i)
    {
        return ch+i ;
    }
    string replaceDigits(string s) {
        int n = s.length() , i ;
        for(i=1;i<n;i++){
            if(i%2!=0){
                int b = (int) s[i]- '0' ; 
                s[i] = shift(s[i-1],b) ;
            }
        }
        return s;
    }
};
