class Solution {
    void floydwarshall(vector<vector<int>>& arr) {
        int n = arr.size();
        for (int i = 0; i < n; ++i) {
            arr[i][i] = 0;
        }
        for (int via = 0; via < n; ++via) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    arr[i][j] = min(arr[i][j], arr[i][via] + arr[via][j]);
                }
            }
        }
    }
    int ans(vector<vector<int>>& arr, int threshold) {
        int res = -1;
        int reach = 1e9, n = arr.size();
        for (int i = 0; i < n; ++i) {
            int count = 0;
            for (int j = 0; j < n; ++j) {
                if (arr[i][j] <= threshold) {
                    ++count;
                }
            }
            if (count <= reach) {
                reach = count;
                res = i;
            }
        }
        return res;
    }

public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> mat(n, vector<int>(n, 1e9));
        for (auto i : edges) {
            mat[i[0]][i[1]] = i[2];
            mat[i[1]][i[0]] = i[2];
        }
        floydwarshall(mat);
        return ans(mat, distanceThreshold);
    }
};
