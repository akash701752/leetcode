class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        if (m == 0) 
            return 0;
        
        int n = obstacleGrid[0].size();
        if (n == 0 || obstacleGrid[0][0] == 1)
            return 0;
            
        int i = 0, j = 0;
        vector<vector<int>> path(m, vector<int>(n, 0));
        
        for (j = 0; j < n; j++)
        {
            if (obstacleGrid[0][j] == 0)
                path[0][j] = 1;
            else 
                break;
        }
            
        for (i = 0; i < m; i++)
        {
            if (obstacleGrid[i][0] == 0)
                path[i][0] = 1;
            else
                break;
        }
        
        for (i = 1; i < m; i++)
        {
            for (j = 1; j < n; j++)
            {
                if (obstacleGrid[i][j] == 0)
                {
                    if (path[i-1][j] != 0)
                        path[i][j] += path[i-1][j];
                        
                    if (path[i][j-1] != 0)
                        path[i][j] += path[i][j-1];
                }
            }
        }
        
        return path[m-1][n-1];
    }
};
