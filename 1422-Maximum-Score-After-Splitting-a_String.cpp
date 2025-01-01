class Solution {
public:
    int maxScore(string s) {
        int len = s.size();
        vector<int> cntZ(len, 0);
        vector<int> cntO(len, 0);
        if (s[0] == '0')
            cntZ[0] = 1;
        if (s[len - 1] == '1')
            cntO[len - 1] = 1;
        for (int i = 1; i < len; i++)
            cntZ[i] += (s[i] == '0') ? cntZ[i - 1] + 1 : cntZ[i - 1];
        for (int i = len - 2; i >= 0; i--)
            cntO[i] += (s[i] == '1') ? cntO[i + 1] + 1 : cntO[i + 1];
        int ans[len], res = 0;
        for (int i = 0; i < len; i++)
        {
            ans[i] = cntZ[i] + cntO[i];
            if (cntZ[i] == 0 || cntO[i] == 0)
                ans[i]--;
            res = max(res, ans[i]);
        }
        return res;    
    }
};
