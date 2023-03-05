class Solution {
public:
    int trap(vector<int>& height)
    {
        int n= height.size() ;
        vector<int> mxl(n) ; // maximum Left
        vector<int> mxr(n) ; // maximum Right
        int i , sum = 0 , j ;
        mxl[0] = height[0] ;
        mxr[n-1] = height[n-1] ;
        //Loop
        for(i=1, j=n-2 ; i<n , j>=0 ; i++ , j--)
        {
            mxl[i] = max(mxl[i-1],height[i]) ;
            mxr[j] = max(mxr[j+1],height[j]) ;
        }
        int area = 0 ;
        for(i=0;i<n;i++)
        {
            area += min(mxl[i],mxr[i]) - height[i] ;
        }
        return area ;
    }
};
