class Solution {
public:
    int gold=0;
    vector<pair<int, int> > choices = {
        {1, 0},{0, -1}, {-1, 0}, {0, 1}
    };
    int getMaximumGold(vector<vector<int>>& grid){
        for(int r=0;r<grid.size();r++){
            for(int c=0;c<grid[0].size();c++){
                if(grid[r][c]!=0) findGold(grid, r, c, 0);
            }
        }
        return gold;
    }
    
    void findGold(vector<vector<int>>& grid, int r, int c, int noOfGold){
        if(r<0 || r>= grid.size() || c<0 || 
                    c>= grid[0].size() || grid[r][c] == 0) return;
        int origin = grid[r][c];
        grid[r][c] = 0;
        gold = max(gold, noOfGold+origin);
        for(auto ch: choices){
            findGold(grid, r+ch.first, c+ch.second, noOfGold+origin);
        }
        grid[r][c] = origin;
    }
};
