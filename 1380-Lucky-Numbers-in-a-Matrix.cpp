class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            int minn = INT_MAX;
            for (int j = 0; j < m; j++)
                minn = min(matrix[i][j], minn);
            for (int j = 0; j < m; j++) {
                if (minn == matrix[i][j]) {
                    bool isMax = true;
                    for (int k = 0; k < n; k++) {
                        if (matrix[i][j] < matrix[k][j]) {
                            isMax = false;
                            break;
                        }
                    }
                    if (isMax)
                        ans.push_back(minn);
                }
            }
        }
        return ans;
    }
};
