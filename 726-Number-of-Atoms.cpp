
class Solution {
public:
    string countOfAtoms(string formula) {
        int n = formula.length();
        stack<unordered_map<string, int>> st;
        unordered_map<string, int> ans;
        st.push({});
        
        for (int i = 0; i < n; ) {
            if (formula[i] == '(') {
                st.push({});
                i++;
            } else if (formula[i] == ')') {
                unordered_map<string, int> temp = st.top();
                st.pop();
                i++;
                int count = 0;
                while (i < n && isdigit(formula[i])) {
                    count = count * 10 + (formula[i] - '0');
                    i++;
                }
                if (count == 0) count = 1;
                for (auto &p : temp) {
                    p.second *= count;
                }
                for (auto &p : temp) {
                    st.top()[p.first] += p.second;
                }
            } else {
                int start = i;
                i++;
                while (i < n && islower(formula[i])) i++;
                string element = formula.substr(start, i - start);
                int count = 0;
                while (i < n && isdigit(formula[i])) {
                    count = count * 10 + (formula[i] - '0');
                    i++;
                }
                if (count == 0) count = 1;
                st.top()[element] += count;
            }
        }
        
        for (auto &p : st.top()) {
            ans[p.first] += p.second;
        }
        
        map<string, int> ordered_ans(ans.begin(), ans.end());
        string result;
        for (auto &p : ordered_ans) {
            result += p.first;
            if (p.second > 1) {
                result += to_string(p.second);
            }
        }
        return result;
    }
};
