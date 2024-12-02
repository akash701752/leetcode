class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int count = 0 , ans = -1;
        istringstream ss(sentence) ;
        string w ;
        int n = searchWord.size() ;
        while(ss>>w){
            count++ ;
            // int ind = w.find(searchWord) ;
            // if(ind!=string::npos){
            //     ans = count ;
            //     break ;
            // }
            if(w.substr(0,n)==searchWord){
                ans = count ;
                break ;
            }
        }
        return ans ;
    }
};
