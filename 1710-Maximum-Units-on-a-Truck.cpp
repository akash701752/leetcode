class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),[&](auto a,auto b){
            return a[1]>b[1] ;
        }) ;
        int ans = 0  ;
        for(auto v : boxTypes){
            int box = min(v[0],truckSize) ;
            ans += box * v[1] ;
            truckSize -= box ;
        }
        return ans ;
    }
};
