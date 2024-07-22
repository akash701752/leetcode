class Solution {
public:
    // static bool comp(pair<int,string> &a,pair<int,string> &b){
    //     return a.first > b.first ;
    // }
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int,string> > v ;
        int i , n = heights.size() ;
        for(i=0;i<n;i++){
            v.push_back({heights[i],names[i]}) ;
        } 
        //sort(v.begin(),v.end(),comp) ;
        sort(v.begin(),v.end(),[&](auto &a,auto &b){
            return a.first > b.first ;
        }) ;
        vector<string> res ;
        for(i=0;i<n;i++){
            res.push_back(v[i].second) ;
        }
        return res ;
    }
};
