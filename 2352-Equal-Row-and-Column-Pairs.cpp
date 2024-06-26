class Solution {
public:
    int equalPairs(vector<vector<int>>& grid){
        vector<vector<int>> cols;
        for(int j=0;j<grid[0].size();j++){
            vector<int> topush;
            for(int i=0;i<grid.size();i++){
                topush.push_back(grid[i][j]);
            }
            cols.push_back(topush);
        }
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<cols.size();j++){
                if(grid[i]==cols[j])ans++;
            }
        }
        return ans;
    }
};
