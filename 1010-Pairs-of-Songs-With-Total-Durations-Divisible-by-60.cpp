class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        long long int n = time.size() , i ;
        vector<long long int> v(60,0) ;
        for(i=0;i<n;i++){
            v[time[i]%60]++ ;
        }
        long long int count = (v[0]*(v[0]-1))/2 ;
        cout<<count <<endl ;
        for(i=1;i<30;++i){
            count += v[i]*v[60-i] ;
        }
        count += (v[30]*(v[30]-1))/2 ;
        return count ;
    }
};
