class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size() , n = matrix[0].size(), i , j ;
        vector<int> row(m,0) , col(n,0);
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                if(matrix[i][j]==0){
                    row[i] = 1 ;
                    col[j] = 1 ; 
                }
            }
        }
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                if(row[i]==1 || col[j]==1){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
