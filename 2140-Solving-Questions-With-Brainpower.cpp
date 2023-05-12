class Solution {
private:
    long long dfs(vector<vector<int>>& questions,int index,vector<long long>& dp){
        if(index >= questions.size())
            return 0;
        if(dp[index] == -1){
            long long op1 = questions[index][0] + dfs(questions,index + questions[index][1] + 1,dp);
            long long op2 = dfs(questions,index + 1,dp);
            dp[index] = max(op1,op2);
        }
        return dp[index];
    }
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n,-1);
        return dfs(questions,0,dp);
    }
};
