class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[&](auto &a,auto b){
            return a[0]<b[0] ;
        });
        int res = 0 , n = intervals.size();
        int left = 0 , right= 1 ;
        while(right<n)
        {
            if(intervals[left][1]<= intervals[right][0]){
                left = right ;
                right++ ;
            }
            else if(intervals[left][1]<=intervals[right][1]){
                res++ ;
                right++ ;
            }
            else if(intervals[left][1]>intervals[right][1]){
                res++ ;
                left = right ;
                right++ ;
            }
        }
        return res ;
    }
};
