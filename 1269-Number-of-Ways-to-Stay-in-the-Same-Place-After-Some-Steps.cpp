class Solution {
public:
    long long dp[10006][505];
    const int mod=1e9+7;
    int find(int length,int index,int step)
    {
        if(index<0||index>=length){
            return 0;
        }
        if(index==0&&step==0){
            return 1;
        }
        if(step<0){
            return 0;
        }
        if(dp[index][step]!=-1){
            return dp[index][step];
        }
        long long x=find(length,index+1,step-1);
        long long y=find(length,index,step-1);
        long long z=find(length,index-1,step-1);
        return dp[index][step]=(x+y+z)%mod;
    }
    int numWays(int steps, int arrLen) 
    {
        memset(dp,-1,sizeof(dp));
        return find(arrLen,0,steps)%mod;
    }
};
