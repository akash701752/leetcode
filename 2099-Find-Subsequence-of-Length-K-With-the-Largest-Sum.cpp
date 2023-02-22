class Solution {
public:
    typedef pair<int,int> p ;
    vector<int> maxSubsequence(vector<int>& nums, int k) 
    {
        priority_queue<p> pq;
        int i , n = nums.size();
        for(i=0;i<n;i++){
            pq.push({nums[i],i});
        }
        vector<int> res;
        for(i=0;i<k;i++){
           res.push_back(pq.top().second) ;
           pq.pop() ;
        }
        sort(res.begin(),res.end()) ;
        for(i=0;i<k;i++){
            res[i] = nums[res[i]] ;
        }
        return res ;
    }
};
