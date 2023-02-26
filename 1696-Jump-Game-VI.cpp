class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq ;
        int maxScore = nums[0] , n = nums.size() , i;
        pq.push({nums[0],0});
        for(i=1;i<n;i++)
        {
            while(pq.size()>0 && pq.top().second < i-k){
                pq.pop() ;
            }
            maxScore = nums[i] + pq.top().first ;
            pq.push({maxScore,i}) ;
        }
        return maxScore ;
    }
};
