class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int> mp ;
        string ans = "" ;
        int c = 0 ;
        for(auto s: arr){
            mp[s]++ ;
        }
        for(auto s: arr){
            if(mp[s]==1){
                c++ ;
            }
            if(c==k){
                ans += s ;
                break ;
            }
        }
        return ans ;
    }
};
