class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
            double matrix[101][101]={0};
                matrix[0][0] = poured;
                for(int r = 0; r <= query_row; r++) {
                    for(int c = 0; c <= r; c++) {
                        double of = (matrix[r][c] - 1.0) / 2.0;
                        if (of > 0) {
                            matrix[r + 1][c] += of;
                            matrix[r + 1][c + 1] += of;
                        }
                    }
                }
                return matrix[query_row][query_glass] < 1 ? matrix[query_row][query_glass] : 1;
    }
};
