class Solution {
public:
    //bellman ford.
    //just run it k+1 iterations.
    int findCheapestPrice(int n, vector<vector<int>>& a, int src, int dst, int k) {
        vector<int> dist(n,1e8) ;
        dist[src] = 0 ;
        for(int i=0;i<k+1;i++)
        {
            vector<int> temp ;
            temp = dist ;
            for(auto it : a){
                temp[it[1]] = min(temp[it[1]],dist[it[0]]+it[2]) ;
            }
            dist = temp ;
        }
        if(dist[dst]==1e8){
            return -1;
        }
        return dist[dst] ;
    }
};
