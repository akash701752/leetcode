class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_map<string,int> mp ;
        vector<string> morseCode = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."} ;

        for(auto s : words)
        {
            int size = s.size() ;
            string temp = "" ;
            for(int i = 0;i<size;i++){
                temp += morseCode[s[i]-'a'] ;
            }
            mp[temp]++ ;
        }
        return mp.size() ;
    }
};
