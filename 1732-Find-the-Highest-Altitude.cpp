class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans = 0 , jump = 0 ;
        for(auto n: gain){
            jump = jump+ n ;
            ans = max(ans,jump) ;
        }
        return ans ;
    }
};
