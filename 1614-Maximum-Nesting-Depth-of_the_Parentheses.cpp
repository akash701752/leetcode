class Solution {
public:
    int maxDepth(string s) {
        int depth = 0 , n = s.length() , i , ans = 0 ;
        for(i=0;i<n;i++){
            if(s[i]=='('){
                depth++ ;
                ans = max(ans,depth) ;
            }
           if(s[i]==')'){
                depth-- ;
            }
        }
        return ans ;
    }
};
