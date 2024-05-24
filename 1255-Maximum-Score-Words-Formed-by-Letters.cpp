class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int n=words.size();
        vector<int> mcnt(26,0);
        for(auto l:letters){
            mcnt[l-'a']++;
        }
        int ans=0;
        for(int i=1;i<pow(2,n);i++){
            vector<int> cnt(26,0);
            int mask=i,flag=1;
            for(int j=0;j<words.size();j++){
                if(mask&(1<<j)){
                    for(auto c:words[j]){
                        cnt[c-'a']++;
                    }
                }
            }
            for(int j=0;j<26;j++){
                if(cnt[j]>mcnt[j]){
                    flag=0;
                    break;
                }
            }
            if(flag){
                int s=0;
                for(int j=0;j<26;j++){
                    s+=score[j]*cnt[j];
                }
                ans=max(ans,s);
            }
        }
        return ans;
    }
};
