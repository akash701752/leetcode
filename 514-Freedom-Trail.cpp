class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int n=key.size();
		int m=ring.size();
		vector<vector<int>> dp(n,vector<int>(m,INT_MAX/2));

		unordered_map<char,vector<int>> Map;// current letter to position

		for(int i=0;i<ring.size();i++){
			Map[ring[i]].push_back(i);
		}

		for(auto& x:Map[key[0]]){
			dp[0][x]=min(dp[0][x],min(x,m-x));
		}

		for(int i=1;i<n;i++){
			for(auto& x:Map[key[i]]){
				for(auto& v:Map[key[i-1]]){
					dp[i][x]=min(dp[i][x],dp[i-1][v]+min(abs(x-v),m-abs(x-v)));
				}
			}
		}

		int ans=INT_MAX;
		for(auto& x:Map[key.back()]){
			ans=min(ans,dp[n-1][x]);
		}

		return ans+n;
    }
};
