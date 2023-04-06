class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq ;
        for(auto g: gifts){
            pq.push(g) ;
        }
        while(k-->0)
        {
            int num = pq.top() ;
            pq.pop();
            num = sqrt(num);
            if(num>0){
                pq.push(num);
            }
        }
        long long ans = 0;
        while(pq.size()>0){
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};
