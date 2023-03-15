class Solution {
public:
    bool strongPasswordCheckerII(string password) {
        int l , u , digit , special , n = password.length() , i ;
        if(n<8){
            return false ;
        }
        l = u = digit = special = 0 ;
        bool flag = false ;
        for(i=0;i<n;i++)
        {
            if(isupper(password[i])){
                u++;
            }
            else if(islower(password[i])){
                l++;
            }
            else if(isdigit(password[i])){
                digit++;
            }
            else{
                special++;
            }
            if(i>0){
                if(password[i-1]==password[i]){
                    flag = true ;
                    break;
                }
            }
        }
        if(l>0 && u>0 && digit>0 && special>0 && flag==false){
            return true ;
        }
        return false ;
    }
};
