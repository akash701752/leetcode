class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<pair<int,int>> v ;
        int i , n = score.size() ;
        for(i=0;i<n;i++){
            v.push_back({score[i],i});
        }
        sort(v.begin(),v.end(),[&](auto &a,auto &b){
            return a.first >b.first ;
        }) ;
        vector<string> res(n);
        for(i=0;i<n;i++){
            if(i==0){
                res[v[i].second] = "Gold Medal" ;
            }
            else if(i==1){
                res[v[i].second] = "Silver Medal" ;
            }
            else if(i==2){
                res[v[i].second] = "Bronze Medal" ;
            }
            else{
                res[v[i].second] = to_string(i+1) ;
            }
        }
        return res;
    }
};
