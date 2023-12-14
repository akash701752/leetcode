class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        
        vector<int> onesInRow;
        vector<int> zeroesInRow;
        vector<int> onesInCol;
        vector<int> zeroesInCol;
        
        int r = grid.size();
        int c = grid[0].size();
        for(int i=0; i<r; i++) {
            int zero = 0;
            int one = 0;
            for(int j=0; j<c; j++) {
                if(grid[i][j] == 0) {
                    zero++;
                }
                if(grid[i][j] == 1) {
                    one++;
                }
            }
            onesInRow.push_back(one);
            zeroesInRow.push_back(zero);
        }
                
        for(int i=0; i<c; i++) {
            int zero = 0;
            int one = 0;
            for(int j=0; j<r; j++) {
                if(grid[j][i] == 0) {
                    zero++;
                }
                if(grid[j][i] == 1) {
                    one++;
                }
            }
            onesInCol.push_back(one);
            zeroesInCol.push_back(zero);
        }
                
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                grid[i][j] = onesInRow[i]+onesInCol[j]-zeroesInRow[i]-zeroesInCol[j];
            }
        }
        return grid;
        
    }
};
