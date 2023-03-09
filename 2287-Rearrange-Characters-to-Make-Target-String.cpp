class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        vector<int> freq(26,0) ;
        for(auto ch:s){
            freq[ch-'a'] ++;
        }
        int ans = 0 ;
        bool flag = true ;
        while(flag)
        {
            int t = 0 ;
            for(auto ch: target){
                cout<<ch << " ";
                if(freq[ch-'a']>0){
                    t++;
                    freq[ch-'a']--;
                }
            }
            if(t==target.length()){
                ans++;
            }
            else{
                flag =false;
                break;
            }
        }
        return ans;
    }
};
