class Solution {
public:
    int countGoodSubstrings(string s) {
        int n = s.length() , i , ans = 0 ;
        for(i=0;i<n-2;i++)
        {
            string temp = s.substr(i,3);
            unordered_map<char,int> mp ;
            for(auto ch: temp){
                mp[ch]++ ;
            }
            if(mp.size()==3){
                ans++;
            } 
        }
        return ans ;
    }
};
