class Solution {
public:
    vector<int> sortArray(vector<int>& nums) 
    {
        priority_queue<int,vector<int>,greater<int>> pq ;
        int i , n = nums.size() ;
        for(auto it : nums){
            pq.push(it) ;
        }
        vector<int> v ;
        while(pq.size()>0){
            v.push_back(pq.top()) ;
            pq.pop() ;
        }
        return v ;
    }
};
