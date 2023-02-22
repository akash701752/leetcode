class Solution {
public:
    bool isPossible(vector<int>& weights,int mid, int days,int n)
    {
        int d = 1 , i , sum = 0 ;
        for(i=0;i<n;i++){
            sum += weights[i] ;
            if(sum>mid){
                d++ ;
                sum = weights[i] ;
            }
        }
        return d <= days ;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int sum = 0 , n= weights.size() , i , mx =INT_MIN ;
        for(i=0;i<n;i++){
            sum += weights[i] ;
            mx = max(mx,weights[i]) ;
        }
        if(n==days){
            return mx;
        }
        int low = mx , high = sum , ans= 0;
        while(low<=high)
        {
            int mid = low+ (high-low)/2 ;
            if(isPossible(weights,mid,days,n)==true){
                ans = mid ;
                high = mid-1;
            }
            else{
                low = mid+1 ;
            }
        }
        return ans ;
    }
};
