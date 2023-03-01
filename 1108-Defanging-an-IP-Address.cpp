class Solution {
public:
    string defangIPaddr(string address) {
        string ans = "" , t = "[.]";
        int n = address.size() , i ;
        for(i=0;i<n;i++){
            if(address[i]=='.'){
                ans += '[' ;
                ans += '.' ;
                ans += ']' ;
            }
            else{
                ans += address[i] ;
            }
        }
        return ans ;
    }
};
