class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0 ;
        int ind = pref.length() ;
        for(auto s: words){
            if(s.length()==1){
                if(pref.compare(s.substr(0,ind))==0){
                    count++ ;
                }
            }
            if(s.length()>=2 && pref.compare(s.substr(0,ind))==0){
                count++;
            }
        }
        return count ;
    }
};
