class Solution {
public:
    int minOperations(string s) {
        int res = 0, sz = s.size();
        for (int i = 0; i < sz; i++) {
            if (i % 2 == 0 && s[i] != '0' ||
                i % 2 != 0 && s[i] != '1')
                res++;
        }
        return min(res, sz - res);
    }
};
