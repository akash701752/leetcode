class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> freq(26,0) ;
        int ans = 0 ;
        for(auto ch: chars){
            freq[ch-'a']++ ;
        }
        for(auto str : words){
            vector<int> temp = freq  ;
            int c = 0 , n = str.length() ;
            for(auto ch : str){
                if(temp[ch-'a']>0){
                    c++;
                    temp[ch-'a']--;
                }
                else{
                    break;
                }
            }
            if(c==n){
                ans += n ;
            }
        }
        return ans;
    }
};
