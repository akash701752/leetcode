class Solution {
public:
    static bool cmp(vector<int> v1, vector<int> v2){
        return v1[1] < v2[1];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();

        sort(pairs.begin(), pairs.end(), cmp);
        int i = 0, j = 1, ans = 1;
        while(j < n){
            if(pairs[i][1] < pairs[j][0])
            {i = j;ans++;}
            j++;
        }
        
        return ans;
    }
};
