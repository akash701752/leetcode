class Solution {
public:
    string removeStars(string s) {
        int i , n = s.length() ;
        string ans = "" ;
        for(i=0;i<n;i++)
        {
            if(s[i]=='*' &&ans.size()>0){
                ans.pop_back();
            }
            else{
                ans += s[i] ;
            }
        }
        return ans ;
    }
};
