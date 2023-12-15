class Solution {
public:
    int ans = 0 ;
    int dfs(vector<int> &cost,int ind,int n){
        if(ind>=n){
            return 0 ;
        }
        int lc = dfs(cost,2*ind+1,n) ;
        int rc = dfs(cost,2*ind+2,n) ;
        
        ans += abs(lc-rc) ;
        return cost[ind]+ max(lc,rc) ;
    }
    int minIncrements(int n, vector<int>& cost) {
        //int ans = 0 ;
        // int height = log2(n) ;
        // for(int i=0;i<height;i++){
        //     int left  = cost[2*i + 1] ;
        //     int right = cost[2*i + 2] ;
        //     count += abs(left-right) ;
        // }
        int d = dfs(cost,0,n) ;
        return ans ;
    }
};
