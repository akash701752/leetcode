class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string,int> mp;
        for (auto p: paths) {
            mp[p[1]]++;
        }
        for (auto p: paths) {
            if(mp.count(p[0])){
                mp.erase(p[0]);
            }
        }
        return mp.begin()->first;
    }
};
