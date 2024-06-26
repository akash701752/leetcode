class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size() , i , j ;
        vector<vector<int>> ans(n-2,vector<int> (n-2,0));
        for(i=1;i<=n-2;i++)
        {
            for(j=1;j<=n-2;j++)
            {
                int mx = INT_MIN;
                mx = max(mx,max(grid[i-1][j-1],max(grid[i-1][j],grid[i-1][j+1]))); 
                mx = max(mx,max(grid[i][j-1],max(grid[i][j],grid[i][j+1]))); 
                mx = max(mx,max(grid[i+1][j-1],max(grid[i+1][j],grid[i+1][j+1])));
                
                ans[i-1][j-1]=mx;
            }
        }
        return ans;
    }
};
