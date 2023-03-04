class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int ans = 0 ;
        for(auto x : words){
            int n = x.length() ;
            if(x == s.substr(0,n)){
                ans ++;
            }
        }
        return ans ;
    }
};
