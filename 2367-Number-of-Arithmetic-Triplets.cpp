class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        unordered_map<int,int> mp;
        int ans = 0;
        for (int num : nums) {
            mp[num]++;
            ans += mp[num - diff] * mp[num - diff*2];
        }
        return ans;
    }
};
