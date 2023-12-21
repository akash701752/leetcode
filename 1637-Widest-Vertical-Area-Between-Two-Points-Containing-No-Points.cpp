class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int mx=INT_MIN;
        int n = points.size() ;
        for(int i=1;i<n;i++){
           mx=max(mx,points[i][0]-points[i-1][0]) ;
        }
        return mx;
    }
};
