class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int l = 0 , n = arr.size() , r ;
        r= n-1;
        if(arr[0]>k){
            return k ;
        }
        while(l<=r){
            int mid = l+ (r-l)/2 ;
            int miss = arr[mid] - (mid+1) ;
            if(miss<k){
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        l--;
        int miss = arr[l] - (l+1);
        return arr[l] + (k-miss) ;
    }
};
