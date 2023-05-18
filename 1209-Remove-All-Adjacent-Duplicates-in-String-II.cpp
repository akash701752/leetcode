class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char,int>> v ;
        int n = s.length() , i ;
        for(i=0;i<n;i++){
            if(v.size()==0){
                v.push_back({s[i],1});
            }
            else if(v.back().first==s[i] && v.back().second==k-1){
                v.pop_back() ;
            }
            else if(v.back().first==s[i]){
                v.back().second++;
            }
            else{
                v.push_back({s[i],1});
            }
        }
        string ans = "" ;
        for(i=0;i<v.size();i++){
            for(int j=0;j<v[i].second;j++){
                ans += v[i].first;
            }
        }
        return ans ;
    }
};
