class Solution {
public:
    void DFS(string cur, vector<string>& res, unordered_map<string, priority_queue<string, vector<string>, greater<string>>>& m){
        while(!m[cur].empty()){
            string s = m[cur].top();
            m[cur].pop();
            DFS(s, res, m);
        }
        res.push_back(cur);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, priority_queue<string, vector<string>, greater<string>>>m;
        vector<string>res;
        for(auto x: tickets) m[x[0]].push(x[1]);
        DFS("JFK", res, m);
        reverse(res.begin(), res.end());
        return res;
    }
};
