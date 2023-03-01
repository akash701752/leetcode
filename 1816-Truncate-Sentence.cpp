class Solution {
public:
    string truncateSentence(string s, int k) {
        istringstream ss(s) ;
        string w ;
        int count = 0 ;
        string ans = "";
        while(ss>>w && count<k){
            count++ ;
            ans += w ;
            ans.push_back(' ');
        }
        ans.pop_back() ;
        return ans ;
    }
};
