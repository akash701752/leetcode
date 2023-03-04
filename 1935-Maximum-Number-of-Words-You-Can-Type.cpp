class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int c = count(text.begin(),text.end(),' ') +1;
        istringstream ss(text) ;
        string w ;
        while(ss>>w){
            int t = 0 ;
            for(auto s : brokenLetters){
                if(count(w.begin(),w.end(),s)>0){
                    t++ ;
                }
            }
            if(t>0){
                c-- ;
            }
        }
        return c ;
    }
};
