class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> v = heights ;
        sort(v.begin(),v.end()) ;
        int i , count =0 , n = heights.size() ;
        for(i=0;i<n;i++){
            if(v[i]!=heights[i]){
                count++ ;
            }
        }
        return count ;
    }
};
