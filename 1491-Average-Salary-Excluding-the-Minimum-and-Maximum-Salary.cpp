class Solution {
public:
    double average(vector<int>& salary) {
        double avg = 0;
        int i, n = salary.size(), mx = INT_MIN, mn = INT_MAX;
        for(i=0;i<n;i++){
            avg +=salary[i];
            mx = max(mx, salary[i]);
            mn = min(mn, salary[i]);
        }
        avg = avg - mn - mx;
        avg = avg/(n-2);
        return avg;
    }
};
