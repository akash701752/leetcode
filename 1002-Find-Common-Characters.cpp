class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> freq1(26,0) , freq2(26,0) ;
        for(auto ch: words[0]){
            freq1[ch -'a']++;
        }
        int i , j  , n = words.size() ;
        for(i=1;i<n;i++)
        {
            for(auto ch: words[i]){
                freq2[ch-'a']++;
            }
            for(j=0;j<26;j++){
                freq1[j] = min(freq1[j],freq2[j]) ;
                freq2[j] = 0 ;
            }
        }
        vector<string> ans ;
        for(i=0;i<26;i++){
            if(freq1[i]>0){
                char ch = i + 'a' ;
                string s = "" ;
                s += ch;
                int count = freq1[i] ;
                while(count-->0){
                    ans.push_back(s) ;
                }
            }
        }
        return ans;
    }
};
