// class Solution {
// public:
//     bool canCross(vector<int>& nums) 
//     {
//         int i , jump = 1 ;
//         bool ans = true ;
//         int n = nums.size() ;  
//         for(i=1;i<n;i++)
//         {
//             if(nums[i]-nums[i-1]<= jump+1)
//             {
//                 jump = nums[i] -nums[i-1] ;
//             }
//             else{
//                 return false ;
//                 break ;
//             }
//         }
//         return ans ;
//     }
// };
class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n=stones.size(),i,j,s;
        
        if(stones[1]!=1 || n<2)return 0;
        if(n==2)return 1;
        
        vector<vector<bool>> dp(n,vector<bool>(n,0));
        dp[1][0]=1;
        
        for(i=2;i<n;i++)
        {
            for(j=1;j<i;j++)
            {
                s=stones[i]-stones[j]-1;
                if(s<n)
                {
                    if(s+1<n && dp[j][s+1])
                        dp[i][s]=1;
                    if(dp[j][s])
                        dp[i][s]=1;
                    if(s-1>=0 && dp[j][s-1])
                        dp[i][s]=1;
                    if(i==n-1 && dp[i][s])
                        return 1;
                }
            }
        }
        return 0;
    }
};
