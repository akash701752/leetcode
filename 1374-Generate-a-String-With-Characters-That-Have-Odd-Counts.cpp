class Solution {
public:
    string generateTheString(int n) {
        string ans = "" ;
        if(n==1){
            return "a" ;
        }
        if(n%2==0){
            while(n-->1){
                ans+='a' ;
            }
            ans+='z';
        }
        else{
            if(n==3){
                ans+='a';
                ans+='b';
                ans+='c' ;
            }
            else{
                while(n-->2){
                    ans+='a';
                }
                ans+= 'b';
                ans+= 'c' ;
            }
        }
        return ans ;
    }
};
