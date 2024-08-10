class Solution {
public:

    int dx[4] = { -1,0,1,0 };
    int dy[4] = { 0,1,0,-1 };

    void dfs(vector<vector<int>> &mat,int i,int j)
    {
        int n = mat.size();
         
        for(int k=0;k<4;k++)
        {
            int ni = i + dx[k];
            int nj = j + dy[k];
            if(ni>=0 && ni<n && nj>=0 && nj<n && mat[ni][nj]==0)
            {
                mat[ni][nj] = -1 ;
                dfs(mat,ni,nj);
            }
        }
    }

    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        vector<vector<int>> mat(3*n,vector<int>(3*n,0));
        for(int j=0;j<n;j++)
        {
            string s = grid[j];
            bool isPrev = false;
            for(int i=0;i<s.length();i++)
            {
                if(s[i]!=' ')
                {
                    if(s[i]=='/')
                    {
                        int row = i*3+2;
                        int col = j*3;
                        mat[row][col] = 1 ; 
                        mat[row][col] = 1 ; 
                        mat[row-1][col+1] = 1 ; 
                        mat[row-2][col+2] = 1 ; 
                        isPrev = false;
                    }
                    else{
                        int row = i*3;
                        int col = j*3 ; 
                        mat[row][col] = 1 ; 
                        mat[row+1][col+1] = 1;
                        mat[row+2][col+2] = 1;
                    }
                }
                else isPrev = false;
            }
        }

        

        

        int comp = 0 ; 
        
        for(int i=0;i<3*n;i++)
        {
            for(int j=0;j<3*n;j++)
            {  
                if(mat[i][j]==0)
                {
                    // cout<<i<<" "<<j<<endl;
                    mat[i][j] = -1 ; 
                    dfs(mat,i,j);
                    comp++;
                }
            }
            
        }
        
        return comp;
    }
};
