class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        int ans = 0 ;
        unordered_map<string,int> mp1 ,mp2  ;
        for(auto s: words1){
            mp1[s]++ ;
        }
        for(auto s: words2){
            mp2[s]++ ;
        }
        for(auto &it: mp2){
            if(mp1.find(it.first)!=mp1.end() && mp1[it.first]==1 && mp2[it.first]==1){
                ans++ ;
            }
        }
        return ans ;
    }
};
