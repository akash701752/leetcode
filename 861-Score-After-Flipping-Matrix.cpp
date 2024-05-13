class Solution {
public:
	int matrixScore(vector<vector<int>>& grid) {
		int row = grid.size();
		int col = grid[0].size();

		for (int x = 0; x < row; x++){
			if (grid[x][0] == 0){
				for (int y = 0; y < col; y++){
					if (grid[x][y] == 1) grid[x][y] = 0;

					else{grid[x][y] = 1;}
				}
			}
		}


		for (int y = 0; y < col; y++){
			int onesCount = 0;
			for (int x = 0; x < row; x++){
				if (grid[x][y] == 1) onesCount++;
			}

			if (onesCount < row - onesCount){ 
				for (int x = 0; x < row; x++){
					if (grid[x][y] == 1) grid[x][y] = 0;

					else{grid[x][y] = 1;}
				}
			}
		}

		int result = 0;

		for (int i = 0; i < row; i++){
			for (int j = 0; j < col; j++){
				if (grid[i][j] == 1) result += pow(2, col-j-1);
			}
		}

		return result;
	}
};
