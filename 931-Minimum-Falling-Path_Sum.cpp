// class Solution {
// public:
//     // vector<vector<int>> dp (101,vector<int>(101,-1)) ;
//     int dp[101][101] ;
//     int solve(vector<vector<int>>& matrix,int i,int j){
//         int n = matrix.size() ;
//         if(i >=n || j >=n || i < 0  || j<0 ){
//             return 1e7 ;
//         }
//         if(i==n-1){
//             return matrix[i][j] ;
//         }
//         if(dp[i][j]!=-1){
//             return dp[i][j] ;
//         }
//         int d = matrix[i][j] + solve(matrix,i+1,j) ;
//         int ld = matrix[i][j] + solve(matrix,i+1,j-1) ;
//         int rd = matrix[i][j] + solve(matrix,i+1,j+1) ;
//         return dp[i][j] = min(d,min(ld,rd)) ;
//     }
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int ans = INT_MAX ,n = matrix.size();
//         for(int i =0;i<101;i++){
//             for(int j=0;j<101;j++){
//                 dp[i][j] = -1 ;
//             }
//         }
//         for(int i = 0 ; i< n ; i++)
//         { 
//             ans = min(ans, solve(matrix,0,i));
//         }
//         return ans ;
//     }
// };
class Solution {

public:
    int minFallingPathSum(vector<vector<int>>& A) {

        for (auto i = 1; i < A.size(); i++) {
            for (auto j = 0; j < A[i].size(); j++) {
                if (j == 0)
                    A[i][j] += min(A[i - 1][j], A[i - 1][j + 1]);
                else if (j == A[i].size() - 1)
                    A[i][j] += min(A[i - 1][j], A[i - 1][j - 1]);
                else
                    A[i][j] += min(A[i - 1][j - 1], min(A[i - 1][j], A[i - 1][j + 1]));
                
            }
        }
        
        int tmp = A.back()[0];
        for (auto i = 0; i < A.back().size(); i++) {
            if (tmp > A.back()[i])
                tmp = A.back()[i];
        }
        
        return tmp;
    }
};
