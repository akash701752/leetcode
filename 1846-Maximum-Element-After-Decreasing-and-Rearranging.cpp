class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        arr[0] = 1;
        if(arr.size() == 1){
            return arr[0];
        }
        for(int i = 1; i < arr.size(); i++) {
            if(abs(arr[i] - arr[i - 1]) <= 1){
                continue;
            }
            arr[i] = arr[i - 1] + 1;
        }
        return arr.back();
    }
};
