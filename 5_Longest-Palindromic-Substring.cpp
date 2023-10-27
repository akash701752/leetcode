// class Solution {
// public:
//     string longestPalindrome(string s)
//     {
//         int n = s.length() ;
//         vector<vector<int>> dp(n+1,vector<int>(n+1));
//         string t = s ;
//         reverse(t.begin(),t.end());
//         for(int i=0;i<n+1;i++){
//             for(int j=0;j<n+1;j++){
//                 if(i==0 || j==0){
//                     dp[i][j] = 0;
//                 }
//                 else{
//                     if(s[i-1]==t[j-1]){
//                         dp[i][j] = 1+ dp[i-1][j-1];
//                     }
//                     else{
//                         dp[i][j] = 0 ;
//                     }
//                 }
//             }
//         }
//         int i = n , j = n ;
//         string ans ;
//         while(i>0 && j>0){
//             if(s[i-1]==t[j-1]){
//                 ans.push_back(s[i]);
//                 i--;
//                 j--;
//             }
//             else if(dp[i][j-1]>dp[i-1][j]){
//                 j--;
//             }
//             else{
//                 i--;
//             }
//         }
//         reverse(ans.begin(),ans.end());
//         return ans;
//     }
// };

class Solution {
public:
    string longestPalindrome(string s)
    {
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1));
        pair<int,int> max;
		
        for(int len  = 0; len < n; len++)
        {
            for(int i =0, j = len; j < n ;i++,j++)
            {
                if(len==0)
                {
                    dp[i][j] = 1;
                    max ={i,j};
                }
                else if(len==1 && s[i]==s[j])
                {
                    dp[i][j] = 1;
                    max = {i,j};
                }
                else if(s[i]==s[j] && dp[i+1][j-1]==1)
                {
                    dp[i][j] = 1; 
                    max = {i,j};
                }
            }
        }
        return s.substr(max.first,(max.second-max.first+1));
    }
};
