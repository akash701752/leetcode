class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        unordered_map<int,int> mp ;
        for(auto n: nums){
            mp[n]++;
        }
        int pair = 0 , left = 0 ;
        for(auto n:mp){
            pair += n.second/2 ;
            left += n.second%2 ;
        }
        vector<int> res; 
        res.push_back(pair) ;
        res.push_back(left) ;
        return res ;
    }
};
