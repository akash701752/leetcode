class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size() , i , mn = abs(arr[0]-arr[1]);
        sort(arr.begin(),arr.end()) ;
        for(i=1;i<n;i++){
            mn = min(mn,abs(arr[i]-arr[i-1])) ;
        }
        vector<vector<int> > res ;
        for(i=1;i<n;i++){
            if(abs(arr[i-1]-arr[i]) == mn){
                res.push_back({arr[i-1],arr[i]}) ;
            }
        }
        return res ;
    }
};
