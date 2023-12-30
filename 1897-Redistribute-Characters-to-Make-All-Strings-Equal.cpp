class Solution {
public:
    bool makeEqual(vector<string>& words) {
        vector<int> freq(26,0);
        int n = words.size() ;
        for(int i=0;i<n;i++){
            for(auto ch: words[i]){
                int ind = ch- 'a';
                freq[ind]++;
            }
        }
        for(int i=0;i<26;i++){
            if(freq[i]%n!=0){
                return false;
            }
        }
        return true;
    }
};
