class Solution {
public:
    bool isPalindrome(string s) {
        string str = "" ;
        int i , n = s.length() , j ;
        for(i=0;i<n;i++){
            if(s[i]>='a' && s[i]<='z'){
                str +=s[i] ;
            }
            else if(s[i]>='A' && s[i]<='Z'){
                str += s[i]+32 ;
            }
            else if(s[i]>=48 && s[i]<=57){
                str += s[i]+32 ;
            }
        }
        i = 0 , j = str.length()-1;
        bool ans = true;
        while(i<j){
            if(str[i]!=str[j]){
                ans = false ;
                break;
            }
            i++;
            j--;
        }
        return ans;
    }
};
