class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long low = 0 , high = 1e14 , ans = 1e14 ;
        sort(time.begin(),time.end()) ;
        int n = time.size() ,i  ;
        while(low<high)
        {
            long long mid = low + (high-low)/2 ;
            long long trip = 0 ;
            for(i=0;i<n;i++){
                trip += mid/time[i] ;    
            }
            if(trip>=totalTrips){
                ans = min(ans,mid) ;
                high = mid;
            }
            else{
                low = mid+1;
            }
        }
        return ans ;
    }
};
