class Solution {
public:
    typedef long long ll;
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        vector<ll>val;
        ll mn=INT_MAX;
        bool flag=false;
        ll extra=0;
        int n=nums.size();
        ll sum=0;
        for(int i=0;i<n;i++){
            ll temp=(nums[i]^k);
            if(temp>nums[i]){
                extra+=(temp-nums[i]);
                val.push_back(temp-nums[i]);
            }
            else{
                mn=min(mn,(nums[i]-temp));
            }
            sum+=nums[i];
        }
        sort(val.begin(),val.end());
        // cout<<sum<<" "<<extra<<" "<<mn<<endl;
        ll ans=sum;
        if(val.size()%2==0){
            ans+=extra;
        }
        else{
            ll value=extra-val[0];
            if(mn!=INT_MAX){
                value=max(value,(extra-mn));
            }
            ans+=value;
        }
        return ans;
    }
};
