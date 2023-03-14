class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        vector<int> freq1(26,0)  ;
        for(auto ch: word1){
            freq1[ch-'a']++ ;
        }
        for(auto ch: word2){
            freq1[ch-'a']-- ;
        }
        bool ans = true ;
        for(auto f: freq1){
            if(abs(f)>3){
                ans = false ;
                break;
            }
        }
        return ans;
    }
};
