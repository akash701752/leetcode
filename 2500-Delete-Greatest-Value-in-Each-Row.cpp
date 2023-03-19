class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int n = grid.size() , i , j , m = grid[0].size();
        for(i=0;i<n;i++){
            sort(grid[i].begin(),grid[i].end()) ;
        }
        int ans = 0 ; 
        for(j=m-1;j>=0;j--)
        {
            int val = grid[0][j] ;
            for(i=1;i<n;i++){
                val = max(val,grid[i][j]) ;
            }
            ans += val ;
        }
        return ans  ;
    }
};
