class Solution {
public:
    typedef pair<float,pair<int,int>> p ;
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<p> pq ;
        int i , j , n= arr.size() ;
        for(i=0;i<n-1;i++){
            for(j=i+1;j<n;j++){
                pq.push({-(float)(arr[i]/(float)arr[j]),{arr[i],arr[j]}}) ;
            } 
        }
        while(k-->1){
            pq.pop() ;
        }
        return {pq.top().second.first,pq.top().second.second} ;
    }
};
