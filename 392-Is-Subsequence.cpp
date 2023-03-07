class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i , j , m = t.size() ,  n  = s.size();
        for(i=0,j=0;i<m && j< n;i++){
            if(s[j] == t[i]){
                j++;
            }
        }
        if(j==n){
            return true ;
        }
        return false;
    }
};
