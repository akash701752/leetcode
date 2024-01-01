class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int assigned = 0;
        for (int i = 0; i < s.size(); i++) {
            if (assigned < g.size() && s[i] >= g[assigned]) {
                assigned++;
            }
        }
        return assigned;
    }
};
