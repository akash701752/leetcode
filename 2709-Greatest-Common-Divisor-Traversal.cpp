class Solution {
        
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> primes = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317};
        map<int, vector<int>> adj_p;
        vector<vector<int>> adj_n(n);
        map<int, bool> visited_p;
        vector<bool> visited_n(n, false);
        
        for (int i = 0; i != n; ++i){
            int num = nums[i];
            for (int p: primes){
                if (num % p == 0){
                    visited_p[p] = false;  // initialize
                    adj_p[p].push_back(i);
                    adj_n[i].push_back(p);
                }
                while (num % p == 0) { num /= p; }
            }
            if (num > 1){
                adj_p[num].push_back(i);
                adj_n[i].push_back(num);
            }
        }
        
        function<void(int, int)> dfs = [&](int x, int is_p){
            if (is_p){
                int p = x;
                if (visited_p[p]) { return; }
                visited_p[p] = true;
                for (int i: adj_p[p]){
                    dfs(i, 0);
                }
            } else {
                int i = x;
                if (visited_n[i]) { return; }
                visited_n[i] = true;
                for (int p: adj_n[i]){
                    dfs(p, 1);
                }
            }
        };
        dfs(0, 0);
        for (int i = 0; i != n; ++i){
            if (!visited_n[i]){
                return false;
            }
        }
        return true;

    }
};
