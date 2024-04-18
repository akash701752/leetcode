class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size() , i, count = 0;
        int n = grid[0].size() , j , repeat = 0 ;
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                if(grid[i][j]==1){
                    count++ ;
                    if(i!=0 && grid[i-1][j]==1){
                        repeat++;
                    }
                    if(j!=0 && grid[i][j-1]){
                        repeat++;
                    }
                }
            }
        }
        int ans = 4*count -2*repeat ;
        return ans ;
    }
};
