class Solution {
private:
    vector<vector<vector<long>>> dp;
    
    int MODULO = 1000000007;
    
    vector<int> rowMove = {-1, 0, 1, 0};
    vector<int> colMove = {0, 1, 0, -1};
    
    int findPathsHelper(int m, int n, int N, int row, int col) {
        if (row >= m || row < 0 ||
            col >= n || col < 0) {
            return 1;
        } else if (N == 0) {
            return 0;  
        } else if (dp[row][col][N] != -1) {
            return dp[row][col][N];
        } 
        
        long totalMoves = 0;
        for (int move = 0; move < rowMove.size(); ++move) {
            totalMoves += findPathsHelper(m, n, N-1, row+rowMove[move], col+colMove[move]);
            totalMoves %= MODULO;
        }
        
        dp[row][col][N] = totalMoves;
        return totalMoves;
    }
public:
    int findPaths(int m, int n, int N, int i, int j) {
        dp = vector<vector<vector<long>>>(m, vector<vector<long>>(n, vector<long>(N+1, -1)));
        
        return findPathsHelper(m, n, N, i, j);
    }
};
