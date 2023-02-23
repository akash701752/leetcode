class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>> v ;
        int n = profits.size() , i ;
        for(i=0;i<n;i++){
            v.push_back({capital[i],profits[i]});
        }
        sort(v.begin(),v.end(),[&](auto &a,auto &b){
            return a.first<b.first ;
        }) ; // sort on the basis of capital
        i = 0 ;
        priority_queue<int> pq ;
        while(k-->0)
        {
            while(i<n && v[i].first <= w){
                pq.push(v[i].second) ;
                i++ ;
            }
            if(!pq.empty()){
                w += pq.top() ;
                pq.pop() ;
            }
        }
        return w ;
    }
};
