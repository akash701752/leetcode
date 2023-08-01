class Solution {
public:
    int countBits(unsigned long long x){
        int num = 0;
        while(x){
            ++num;
            x = x & (x - 1);
        }
        return num;
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        unsigned long long x = (1 << n) - 1;
        for(unsigned long long i = 0;i <= x; ++i){
            if(countBits(i) == k){
                vector<int> tmp;
                for(int j = 0;j < n; ++j){
                    if(i & (1 << j)){
                        tmp.push_back(j + 1);
                    }
                }
                ans.push_back(tmp);
            }
        }
        return ans;
    }
};
