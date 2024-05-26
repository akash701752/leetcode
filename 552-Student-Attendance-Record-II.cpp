class Solution {
public:
    int checkRecord(int n) {
        long A0 = 1, A1 = 1, L0 = 1, L1 = 0, LL0 = 0, LL1 = 0;
        long MOD = 1000000007;
        for(int i = 1;i<n;i++){
            long A0p = A0, A1p = A1, L0p = L0, L1p = L1, LL0p = LL0, LL1p = LL1;
            A0 = (A0p+L0p + LL0p)%MOD;
            A1 = (L0p+A1p+L1p+A0p + LL1p + LL0p)%MOD;
            L0 = A0p%MOD;
            L1 = A1p%MOD;
            LL0 = L0p%MOD;
            LL1 = L1p%MOD;
        }
        return (A0 + A1 + L0 +L1 + LL0 +LL1)%MOD;
    }
};
