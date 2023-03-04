class Solution {
public:
    int maximumValue(vector<string>& strs) {
        int ans = 0 ;
        for(auto s : strs)
        {
            bool flag = true ;
            for(auto ch : s){
                if(!isdigit(ch)){
                    flag = false ;
                    break ;
                }
            }
            if(flag){
                ans = max(ans,stoi(s)) ;
            }
            else{
                int n = s.length() ;
                ans = max(ans,n) ;
            }
        }
        return ans ;
    }
};
