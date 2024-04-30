class Solution {
public:
    long long wonderfulSubstrings(string word) {
        int n = word.size() ;
        int mask = 0 ;
        long long ans = 0 ;
        unordered_map<int,long long> mp ;
        mp[0] = 1 ;
        for(int i=0;i<n;i++){
            mask = mask ^ (1<< (word[i]- 'a')) ;
            for(int j=0;j<10;j++){
                int ind = 1<<j ;
                ans += mp[mask^ind];
            }
            ans += mp[mask] ;
            mp[mask]++;
        }
        return ans;
    }
};
