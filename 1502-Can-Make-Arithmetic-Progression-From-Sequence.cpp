class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int r = arr[1] - arr[0] , i , n = arr.size();
        bool valid = true;
        for(i=1;i<n-1;i++){
            if(arr[i+1]-arr[i]!=r){
                valid = false;
                break;
            }
        }
        return valid;
    }
};
