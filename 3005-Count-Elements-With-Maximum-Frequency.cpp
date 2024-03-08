class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        // unordered_map<int,int> mp;
        // for(auto x: nums){
        //     mp[x]++;
        // }
        // int mx = 0, ans = -1;
        // for(auto it: mp){
        //     if(it.second > mx){
        //         ans = it.first ;
        //         mx = it.second;
        //     }
        // }
        // return ans;
        int ans=0;
        unordered_map<int,int> map;
        for(auto it : nums){
            map[it]++;
            ans=max(ans,map[it]);
        }
        int res=0;
        for(auto it : map)
            if(it.second == ans) res+=it.second;
        return res;
    }
};
