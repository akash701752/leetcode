class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> pq ;
        int i , j , n = matrix.size();
        for(i=0;i<n;i++)
        {
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
