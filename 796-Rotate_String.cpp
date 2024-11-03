class Solution {
public:
    bool rotateString(string s, string goal) {
        bool flag = false ;
        int n = s.length() , i ;
        if(n!=goal.length()){
            return false ;
        }
        for(i=0;i<n;i++){
            string str1 = s.substr(i,n-i) ;
            string str2 = s.substr(0,i) ;
            str1 += str2 ;
            if(str1==goal){
                flag = true ;
                break ;
            }
        }
        return flag ;
    }
};
