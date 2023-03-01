class Solution {
public:
    string interpret(string command) {
        string ans = "" ;
        bool flag = false ;
        int count = 0 ;
        for(auto s : command)
        {
            if(s=='(' && count==0 && flag==false){
                //count ++;
                flag = true ;
                continue ;
            }
            else if(flag==true && s!=')'){
                count ++;
            }
            else if(s==')' && count >0){
                ans += 'a';
                ans += 'l' ;
                count= 0 ;
                flag = false ;
            }
            else{
                if(flag==true && count==0){
                    ans += 'o' ;
                    flag = false ;
                }
                else{
                    ans += s ;
                }
            }
        }
        return ans ;
    }
};
