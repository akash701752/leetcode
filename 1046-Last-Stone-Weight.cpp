class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq ;
        int i , n= stones.size() ;
        if(n==1){
            return stones[0] ;
        }
        for(i=0;i<n;i++){
            pq.push(stones[i]);
        }
        while(pq.size()>1)
        {
            int stone1 = pq.top() ;
            pq.pop();
            int stone2 = pq.top() ;
            pq.pop();
            if(stone1!=stone2){
                pq.push(abs(stone1-stone2));
            }
        }
        return pq.size() ?  pq.top() : 0;
    }
};
