class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n=s.length();
        vector<int>dp(n+1,n);
        map<string,int>mp;
        for(auto &x:dictionary){
            reverse(x.begin(),x.end());
            mp[x]++;
        }
        for(int i=0;i<n;i++){
            string temp;
            for(int j=i;j>=0;j--){
                temp.push_back(s[j]);
                int extra=mp.find(temp)==mp.end()?temp.size():0;
                if(j)
                  dp[i]=min(dp[i],dp[j-1]+extra);
                else dp[i]=min(dp[i],extra);
           }
        }
        return dp[n-1];
    }
};
