class Solution {
public:
    int countHomogenous(string s) {
        int res = 0, sz = s.size();
        const unsigned int mod = 1000000007;
        for (int i = 0, start = 0; i < sz; i++) {
            start = i;
            while (i + 1 < sz && s[i + 1] == s[start]){
                i++;
            }
            unsigned long long cnt = i - start + 1;
            res += (cnt * (cnt + 1) / 2) % mod;
        }
        return res;
    }
};
