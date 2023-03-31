class Solution {
public:
    int n, m;
    long long int cnt[59][59];
    long long int dp[51][51][11];
    long long int mod = 1000000007;
    long long int findCount(int i , int j ) {
        return cnt[n][m] - cnt[i][m] - cnt[n][j] + cnt[i][j];
    }
    long int solve(int idx, int jdx, int k, int total) {
        if(k == 0){
            return 1;
        }
        if(idx == n  || jdx == m ){
            return 0;
        }
        if(dp[idx][jdx][k] != -1){
            return dp[idx][jdx][k];
        }
        long long int ans = 0;
        long long downcntr;
        long long upcntr;
        for(int i = idx + 1; i <= n - 1; i++) {
            downcntr = findCount(i, jdx);
            upcntr = total - downcntr;
            if(downcntr != 0 && upcntr != 0) {
                ans %= mod;
                ans += solve(i, jdx, k - 1, total - upcntr);
            }
        } 
        for(int j = jdx + 1; j <= m - 1; j++) { 
            downcntr = findCount(idx, j);
            upcntr = total - downcntr; 
            if(downcntr != 0 && upcntr != 0) {
                ans %= mod;
                ans += solve(idx, j, k - 1, total - upcntr);
            } 
        }
        return dp[idx][jdx][k] = ans%mod;
    }
    int ways(vector<string>& pizza, int k) {
        this->n = pizza.size();
        this->m = pizza[0].size();
        memset(dp, -1, sizeof(dp));
        int total = 0;
        for(int i = 1; i <= n; i++) {
            total += (pizza[i - 1][0] == 'A');
            cnt[i][1] = cnt[i - 1][1] + (pizza[i - 1][0] == 'A');
        }
        for(int i = 1; i <= m; i++) {
            total += (pizza[0][i - 1] == 'A');
            cnt[1][i] = cnt[1][i - 1] + (pizza[0][i - 1] == 'A');
        } 
        for(int i = 2; i <= n; i++) 
            for(int j = 2; j <= m; j++) {
                total += (pizza[i - 1][j - 1] == 'A');
                cnt[i][j] = cnt[i - 1][j] + cnt[i][j - 1] - cnt[i - 1][j - 1]+ (pizza[i - 1][j - 1] == 'A');
            }
        if(pizza[0][0] == 'A'){
            total--;
        }
        return solve(0, 0, k - 1, total);
    }
};
