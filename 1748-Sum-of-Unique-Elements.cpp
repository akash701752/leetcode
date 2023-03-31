class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int,int> mp ;
        for(auto n:nums){
            mp[n]++;
        }
        int sum = 0 ;
        for(auto it:mp){
            if(it.second==1){
                sum += it.first ;
            }
        }
        return sum ;
    }
};
