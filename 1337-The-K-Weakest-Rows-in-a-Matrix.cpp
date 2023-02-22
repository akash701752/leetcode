class Solution {
public:
    typedef pair<int,int> p ;
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<p, vector<p> , greater<p> > pq ;
        int i , j , m = mat.size() , n = mat[0].size() ;
        vector<int> res;
        for(i=0;i<m;i++){
            int count = 0 ;
            for(j=0;j<n;j++){
                if(mat[i][j]==1){
                    count++ ;
                }
            }
            pq.push({count,i}) ;
        }
        for(i=0;i<k;i++){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};
