class Solution {
public:
    int trap(vector<int>& height)
    {
        int n = height.size() ;
        // Maximum left and Maximum Right
        vector<int> mxl(n) , mxr(n) ;
        mxl[0] = height[0] ;
        mxr[n-1] = height[n-1] ;

        for(int i=1, j=n-2; i<n, j>=0 ; i++, j--){
            mxl[i] = max(mxl[i-1], height[i]) ;
            mxr[j] = max(mxr[j+1], height[j]) ;
        }
        int area = 0 ;

        for(int i=0;i<n;i++){
            area += min(mxl[i],mxr[i]) - height[i] ;
        }
        return area;
    }
};
