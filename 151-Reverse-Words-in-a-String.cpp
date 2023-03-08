class Solution {
public:
    string reverseWords(string s) 
    {
        istringstream ss(s) ;
        vector<string> v ;
        string w , ans = "" ;
        while(ss>>w){
            v.push_back(w) ;
        }
        int n = v.size() , i ;
        for(i=n-1;i>=0;i--){
            ans += v[i] ;
            ans.push_back(' ');
        }
        ans.pop_back();
        return ans ;
    }
};
