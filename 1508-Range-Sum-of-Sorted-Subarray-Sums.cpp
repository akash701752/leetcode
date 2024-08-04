class Solution {
public:
    const int M = 1e9 + 7;
    int rangeSum(vector<int>& nums, int n, int l, int r) {
        vector<int> temp;
        int ans=0;

        for(int i=0;i<n;i++){
            int sum=nums[i];
            temp.push_back(sum);
            for(int j=i+1;j<n;j++){
                sum+=nums[j];
                temp.push_back(sum);
            }
        }

        sort(begin(temp),end(temp));

        for(int i=l-1;i<r;i++){
            ans=(ans+temp[i])%M;
        }

        return ans;
    }
};
