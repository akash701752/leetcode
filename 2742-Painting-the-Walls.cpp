class Solution {
public:
    
    vector<vector<int>> dp;
    vector<int> C;
    vector<int> T;
    int n;
    int off;
    int solve(int idx,int f){
        if(idx == n){
            if(f<=0)return 0;
            return 1e9;
        }
        
        int &x = dp[idx][f+off];
        if(x !=-1)return x;
        
        int ans = 1e9;
        ans = solve(idx+1,f+1);
        ans = min(ans,solve(idx+1,max(-off,f-T[idx]))+C[idx]);
        
        return x = ans;
    } 
    int paintWalls(vector<int>& cost, vector<int>& time) {
        n = cost.size();
        C = cost;
        T = time;
        off = n;
        dp.resize(n,vector<int> ((off*2)+7,-1));
        return solve(0,0);        
    }
};
