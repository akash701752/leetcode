class Solution {
private:
    long long computeCost(vector<int> arr, vector<int> cost, long long N, long long X) {
        long long ans = 0;
        for (int i = 0; i < N; i++)
            ans += abs(arr[i] - X)*cost[i]*1LL;
        return ans;
    }
public:
    long long minCost(vector<int>& arr, vector<int>& cost) {
        int N=arr.size();
        long long low, high;
        low = high = arr[0];
        for (int i = 0; i < N; i++) {
            if (low > arr[i]) low = arr[i];
            if (high < arr[i]) high = arr[i];
        }
        while ((high - low) > 2) {
            long long mid1 = low + (high - low) / 3;
            long long mid2 = high - (high - low) / 3;
            long long cost1 = computeCost(arr,cost, N, mid1);
            long long cost2 = computeCost(arr,cost, N, mid2);
            if (cost1 < cost2) high = mid2;
            else low = mid1;
        }
        long long ans=LLONG_MAX;
        for (long long i=low;i<=high;i++) {
            ans=min(ans,computeCost(arr,cost, N, i));
        }
        return ans;
    }
};
