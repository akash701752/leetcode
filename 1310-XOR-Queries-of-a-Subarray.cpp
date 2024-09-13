class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int x = 0;
        int l = 0,r = 0;
        for (int i = 0; i < arr.size(); i++) {
            x = x ^ arr[i];
            arr[i] = x;
        }
        vector<int> v;
        for (int i = 0; i < queries.size(); i++) {
            l = queries[i][0];
            r = queries[i][1];
            x = 0;
            if (l == 0) {
                v.push_back(arr[r]);
            } else {
                v.push_back(arr[r] ^ arr[l - 1]);
            }
        }
        return v;
    }
};
