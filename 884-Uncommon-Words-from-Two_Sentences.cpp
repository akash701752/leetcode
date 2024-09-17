class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int> mp1, mp2 ;
        istringstream ss(s1) ;
        string w ;
        while(ss>>w){
            mp1[w]++ ;
        }
        istringstream ss2(s2) ;
        while(ss2>>w){
            mp2[w]++ ;
        }
        vector<string> ans ;
        istringstream ss3(s1) ;
        while(ss3>>w){
            if(mp2.find(w)==mp2.end() && mp1[w]==1){
                ans.push_back(w) ;
            }
        }
        istringstream ss1(s2) ;
        while(ss1>>w){
            if(mp1.find(w)==mp1.end() && mp2[w]==1){
                ans.push_back(w) ;
            }
        }
        return ans ;
    }
};
