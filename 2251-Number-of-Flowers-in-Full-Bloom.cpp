class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>> &flowers, vector<int> &persons) {
        priority_queue<int, vector<int>, greater<int>> starts, ends;
        for (vector<int> &flower : flowers) {
            starts.push(flower[0]);
            ends.push(flower[1]);
        }
        vector<int> res(persons.size());
        vector<pair<int, int>> per;
        per.reserve(persons.size());
        for (int i = 0; i < persons.size(); i++) {
            per.push_back({persons[i], i});
        }
        sort(per.begin(), per.end());
        int cur = 0;
        for (pair<int, int> &p : per) {
            while (!starts.empty() && starts.top() <= p.first) {
                cur++;
                starts.pop();
            }
            while (!ends.empty() && ends.top() < p.first) {
                cur--;
                ends.pop();
            }
            res[p.second] = cur;
        }
        return res;
    }
};
