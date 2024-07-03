class Solution {
public:
    int minDifference(vector<int>& arr) {
        if(arr.size()<=4){
            return 0;
        }
        sort(arr.begin(),arr.end());
        int x = min(abs(arr[1]-arr[arr.size()-3]),abs(arr[2]-arr[arr.size()-2]));
        int y = min(abs(arr[0]-arr[arr.size()-4]),abs(arr[arr.size()-1]-arr[3]));
        return min(x,y);
    }
};
