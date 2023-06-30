class Solution {
public:
    bool dfs(vector<vector<int>>& grid, vector<vector<bool>>& visit, int i, int j){
    if(i<0 or j<0 or i>=grid.size() or j>=grid[0].size() or grid[i][j]==1 or visit[i][j])
        return false;
    if(i == grid.size()-1)
        return true;
    
    visit[i][j] = true;
    
    return dfs(grid, visit, i+1, j)  || dfs(grid, visit, i-1, j) || dfs(grid, visit, i, j+1) || dfs(grid, visit, i , j-1);
    
}
int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
    int s =col-1;
    int e = cells.size()-1;
    
    while(s<e){
        int mid = (s+e)/2;
        vector<vector<int>> grid(row, vector<int>(col,0));
        vector<vector<bool>> visit(row, vector<bool>(col,false));
        for(int i=0; i<=mid; i++){
            grid[cells[i][0]-1][cells[i][1]-1] = 1;
        }
        bool flag = false;
        for(int i=0; i<grid[0].size(); i++){
            if(grid[0][i] == 0 and dfs(grid, visit, 0 , i)){
                s=mid+1;
                flag = true;
                break;
            }
        }
        
        if(!flag)
            e=mid;
    }
    return s;
}
};
