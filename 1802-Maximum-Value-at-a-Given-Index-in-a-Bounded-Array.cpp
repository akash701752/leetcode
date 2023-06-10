class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        long long l = 0, r = 1e9+7;
        long long ans = 1;
        while(l < r) {
            long long mid = (l + r) / 2;
            long long ll = index, rl = n - index;
            long long leftValue = (mid - 1 + max(mid - ll, 1ll)) * (mid <= ll ? (mid - 1) : ll)  / 2 + (mid <= ll ? (ll - mid + 1) : 0);
            long long rightValue = (mid + max(mid - rl + 1, 1ll)) * (mid < rl ? mid : rl)  / 2 + (mid < rl ? (rl - mid) : 0);
            if(maxSum >= leftValue + rightValue) {
                l = mid + 1;
                ans = max(ans, mid);
            }else {
                r = mid;
            }
                
        }
        return ans;
    }
};
