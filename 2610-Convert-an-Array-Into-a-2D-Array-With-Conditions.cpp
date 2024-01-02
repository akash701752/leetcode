class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int count = 0;
        int freq[201] = {0};
        for (int n : nums) {
            count++;
            freq[n]++;
        }
        vector<vector<int>> ans;
        while (count) {
            vector<int> row;
            for (int i = 1; i <= 200; i++) {
                if (freq[i]) {
                    row.push_back(i);
                    count--;
                    freq[i]--;
                }
            }
            ans.push_back(row);
        }
        return ans;
    }
};
