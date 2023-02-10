//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int getPairsCount(int arr[], int n, int target) {
        // code here
        unordered_map<int,int> mp ;
        int count = 0 , i ;
        for(i=0;i<n;i++){
            mp[arr[i]] ++  ;
        }
        for(i=0;i<n;i++){
            int val = target - arr[i] ;
            if(mp.find(val)!=mp.end())
            {
                mp[arr[i]] -- ;
                count += mp[val] ;
            }
        }
        return count ;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getPairsCount(arr, n, k);
        cout << ans << "\n";
    }
    
    return 0;
}
// } Driver Code Ends