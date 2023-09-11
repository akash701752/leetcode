class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& a) {
        map< int, vector<int>> m;
        vector<vector<int>> an;
        int i,j;
        vector<int> te;
        pair<int,int> t[a.size()];
        for (i=0;i<a.size();i++){
            t[i].first=a[i];
            t[i].second=i;
        }
        sort(t,t+a.size());
        for ( i=0;i<a.size();i+=(t[i].first)){
            te.clear();
            for( j=0;j<t[i].first;j++)
                te.push_back(t[j+i].second);
            an.push_back(te);
        }
        return an;
    }
};
