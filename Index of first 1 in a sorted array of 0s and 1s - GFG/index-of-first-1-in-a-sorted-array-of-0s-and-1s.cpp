//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int firstIndex(int a[], int n) 
    {
        // Your code goes here
        int l , r , res = -1;
        l = 0 , r = n-1 ;
        while(l<=r){
            int mid = l+ (r-l)/2 ;
            if(a[mid]==1){
                res = mid ;
                r = mid-1;
            }
            else if(a[mid]<1){
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        return res ;
    }
    
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int a[n];

        for (int i = 0; i < n; i++) cin >> a[i];
        Solution ob;
        cout << ob.firstIndex(a, n) << endl;
    }
}
// } Driver Code Ends