class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map<int,int> mp ;
        int i , n = nums.size();
        for(i=0;i<n;i++){
            mp[nums[i]]++ ;
        }
        priority_queue<pair<int,int>> pq ;
        for(auto it:mp){
            pq.push({it.second,it.first}) ;
        }
        vector<int> res;
        for(i=0;i<k;i++){
            res.push_back(pq.top().second) ;
            pq.pop() ;
        }
        return res ;
    }
};
