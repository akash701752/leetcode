class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ans = 0 , i , j , row =  accounts.size() , col = accounts[0].size();
        for(i=0;i<row;i++){
            int sum = 0 ;
            for(j=0;j<col;j++){
                sum+= accounts[i][j] ;
            }
            ans = max(ans,sum) ;
        }
        return ans ;
    }
};
