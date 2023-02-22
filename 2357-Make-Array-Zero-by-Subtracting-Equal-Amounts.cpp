class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        priority_queue<int,vector<int>,greater<int>> pq ; // Min Heap
        int i, n = nums.size() ;
        for(i=0;i<n;i++){
            pq.push(nums[i]) ;
        }
        int ans = 0 , num = 0 ;
        while(pq.size()>0)
        {
            if(pq.top()==0 || pq.top()-num==0){
                pq.pop() ;
            }
            else
            {
                int temp = pq.top() - num ;
                num += temp ;
                pq.pop() ;
                ans++ ;
            }
        }
        return ans ;
    }
};
