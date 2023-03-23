class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans = 0 , i , j , row = grid.size() , col = grid[0].size();
        for(i=0;i<row;i++)
        {
            int low = 0 , high = col-1 , res = -1; 
            while(low<=high){
                int mid = low+ (high-low)/2 ;
                if(grid[i][mid]<0){
                    res = mid ;
                    high = mid-1;
                }
                else if(grid[i][mid]>=0){
                    low = mid+1;
                }
            }
            if(res!=-1){
                ans += col- res ;
            }
        }
        return ans ;
    }
};
