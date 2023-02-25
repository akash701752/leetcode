class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        priority_queue<int,vector<int>,greater<int>> pq ; // Min Heap
        int m = matrix.size() , n = matrix[0].size() , i, j;
        for(i=0;i<m;++i){
            for(j=1;j<n;++j){
                matrix[i][j] = matrix[i][j] ^ matrix[i][j-1] ;
            }
        }
        for(j=0;j<n;++j)
        {
            for(i=1;i<m;++i){
                matrix[i][j] = matrix[i][j] ^ matrix[i-1][j] ;
            }
        }
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                pq.push(matrix[i][j]) ;
                if(pq.size()>k){
                    pq.pop() ;
                }
            }
        }
        return pq.top() ;
    }
};
