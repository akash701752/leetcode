class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq ;
        int i, n = piles.size() ;
        for(i=0;i<n;i++){
            pq.push(piles[i]);
        }
        int sum = 0 ;
        while(k-->0){
            int n = pq.top() ;
            pq.pop() ;
            pq.push(n-n/2);
        }
        while(pq.size()>0){
            sum += pq.top() ;
            pq.pop() ;
        }
        return sum ;
    }
};
