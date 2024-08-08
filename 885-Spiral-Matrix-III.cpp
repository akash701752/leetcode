class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>>ans;
        ans.push_back({rStart,cStart});
        int currRow=rStart;
        int currCol=cStart;
        int nextRow=rStart+1;
        int nextCol=cStart+1;
        int prevRow=rStart-1;
        int prevCol=cStart-1;

        int count=1;
        int total=rows*cols;

        while(count < total){
            
            while(currCol < cols && currCol+1 <= nextCol){
                currCol++;
                if(currRow >= 0 && currRow < rows && currCol >= 0 && currCol < cols){
                    ans.push_back({currRow,currCol});
                    count++;
                }
            }
            nextCol++;

            while(currRow < rows && currRow + 1 <= nextRow){
                currRow++;
                if(currRow >= 0 && currRow < rows && currCol >= 0 && currCol < cols){
                    ans.push_back({currRow,currCol});
                    count++;
                }
            }
            
            nextRow++;

            while(currCol >= 0 && currCol -1 >= prevCol){
                currCol--;
                if(currRow >= 0 && currRow < rows && currCol >= 0 && currCol < cols){
                    ans.push_back({currRow,currCol});
                    count++;
                }
            }
            prevCol--;

            while(currRow >= 0 && currRow - 1 >= prevRow){
                currRow--;
                if(currRow >= 0 && currRow < rows && currCol >= 0 && currCol < cols){
                    ans.push_back({currRow,currCol});
                    count++;
                }
            }
            prevRow--;
        }
        return ans;
    }
};
