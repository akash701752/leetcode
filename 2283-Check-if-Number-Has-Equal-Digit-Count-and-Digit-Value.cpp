class Solution {
public:
    bool digitCount(string num) {
        vector<int> v(10,0) ;
        for(auto s: num){
            v[s-'0']++;
        }
        int i , n = num.size() ;
        bool ans = true ;
        for(i=0;i<n;i++){
            if(v[i]!=num[i]-'0'){
                ans = false ;
                break ;
            }
        }
        return ans ;
    }
};
