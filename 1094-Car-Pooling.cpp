class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
       sort(trips.begin(),trips.end(),[&](auto &a,auto b){
           return a[1]<b[1] ;
       }) ;
       vector<pair<int,int>> v ; // capacity , dest
       bool ans = true ;
       int curr = 0 ;
       for(auto t : trips)
       {
           curr = t[1] ;
           for(int i=0;i<v.size();i++){
               if(v[i].second!=-1 && v[i].second<=curr){
                   capacity += v[i].first ;
                   v[i].first = -1 ;
                   v[i].second = -1 ;
               }
           }
           if(capacity>= t[0]){
               capacity -= t[0] ;
               v.push_back({t[0],t[2]}) ;
           }
           else{
               ans = false ;
               break ;
           }
       }
       return ans ;
    }
};
