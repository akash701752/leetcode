class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n = cost.size();
        vector<vector<long long>> dist(26, vector<long long>(26, LLONG_MAX));
        
        for(int i = 0; i < cost.size(); i++){
            dist[original[i]-'a'][changed[i]-'a'] = min((long long)cost[i], dist[original[i]-'a'][changed[i]-'a']);
        }
        
        for(int k = 0; k < 26; k++){
            for(int i = 0; i < 26; i++){
                for(int j = 0; j < 26; j++){
                    if(i == j){
                        dist[i][j] = 0;
                        continue;
                    }
                    if(dist[i][k] < LLONG_MAX && dist[k][j] < LLONG_MAX){
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
        long long ans = 0;
        for(int i = 0; i < source.size(); i++){
            if(dist[source[i]-'a'][target[i]-'a'] == LLONG_MAX) {
                return -1;
            }
            ans += dist[source[i]-'a'][target[i]-'a'];
        }
        
        return ans;
    }
};
