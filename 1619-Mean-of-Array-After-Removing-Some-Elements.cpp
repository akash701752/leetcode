class Solution {
public:
    double trimMean(vector<int>& arr) {
        sort(arr.begin(),arr.end()) ;
        int n = arr.size() , remove = (n*5)/100 , i ;
        double sum = 0 ;
        for(i=remove;i<n-remove;i++){
            sum += arr[i] ;
        }
        double mean = sum/(n-(2*remove)) ;
        return mean  ;
    }
};
