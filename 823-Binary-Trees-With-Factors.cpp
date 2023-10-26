class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        unordered_map<int,long long> mp;
        long long mod=1e9+7;
        long long ans=0;
        for(int i=0;i<arr.size();i++)
        {
            int sum=1;
            for(int j=0;j<=i;j++)
            {
                if(arr[i]%arr[j]==0 && mp[arr[i]/arr[j]]>=1)
                {
                    sum=(sum%mod+(mp[arr[j]]*mp[arr[i]/arr[j]])%mod)%mod;
                }
            }
            mp[arr[i]]=sum;
            ans=(ans%mod+mp[arr[i]]%mod)%mod;
        }
        return ans;
    }
};
