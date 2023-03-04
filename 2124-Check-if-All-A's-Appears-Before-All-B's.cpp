class Solution {
public:
    bool checkString(string s) {
        bool flag = false , ans = true ;
        int n = s.length() , i ;
        for(i=n-1;i>=0;i--){
            if(!flag && s[i]=='b'){
                continue ;
            }
            else if(!flag && s[i]=='a'){
                flag = true ;
            }
            else if(flag && s[i]=='b'){
                ans = false ;
                break ;
            }
        }
        return ans;
    }
};
