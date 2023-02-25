class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int,int> mp ;
        if(barcodes.size()<=2){
            return barcodes; 
        }
        for(auto it : barcodes){
            mp[it]++ ;
        }
        priority_queue<pair<int,int>> pq ;
        for(auto it : mp) {
            pq.push({it.second,it.first}) ;
        }
        int ind = 0 ;
        vector<int> v ;
        while(pq.size()>0)
        {
            int f1 = pq.top().first ; 
            int n1 = pq.top().second ; 
            pq.pop() ;
            barcodes[ind++] = n1 ;
            if(pq.size()==0){
                break ;
            }
            int f2 = pq.top().first ;
            int n2 = pq.top().second ; 
            pq.pop() ;
            barcodes[ind++] = n2 ;
            f1 -- ;
            f2 -- ;
            if(f1>0){
                pq.push({f1,n1}) ;
            }
            if(f2>0){
                pq.push({f2,n2}) ;
            }
        }
        return barcodes;
    }
};
