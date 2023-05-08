class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int m = mat.size() , n = mat[0].size() , sum = 0 ;
        if(m==1 && n==1){
            return mat[0][0] ;
        }
        for(int i=0; i<m;i++){
            for(int j =0; j<n; j++){
                     if(i== j || (i+j == n-1)){    
                         sum+=mat[i][j];
                     }
            }
        }
        return sum;
    }
};
