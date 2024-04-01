class Solution {
public:
    int lengthOfLastWord(string s) {
        istringstream ss(s) ;
        string str ;
        while(ss>>str){};
        
        return str.length();
    }
};
