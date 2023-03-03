class Solution {
public:
    bool areOccurrencesEqual(string s) {
        int c = count(s.begin(),s.end(),s[0]);
        int i , n = s.length() ;
        for(i=0;i<n;i++){
            if(count(s.begin(),s.end(),s[i])!=c){
                return false;
            }
        }
        return true;
    }
};
