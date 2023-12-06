class Solution {
public:
    int totalMoney(int n) {
        int w = n / 7;
        int d = n % 7;
        return w  * (w-1) / 2 * 7 + w * 28 + d * (d + 1) / 2 + d * w;
    }
};
