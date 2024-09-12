class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<char,int> mp   ;
        for(auto it: allowed){
            mp[it] = 1;
        }
        int ans = 0 ;
        for(auto s : words){
            int size = s.length() , c = 0 ;
            for(auto i : s){
                if(mp.find(i)!=mp.end()){
                    c++ ;
                }
            }
            if(c==size){
                ans++ ;
            }
        }
        return ans ;
    }
};
