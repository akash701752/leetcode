class Solution {
public:
    int minBitFlips(int start, int goal) {
        int x = start ^ goal;
        int cnt = 0;

        while (x > 0) {
            cnt += x & 1;
            x/=2;
        }

        return cnt;
    }
};
