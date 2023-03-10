//{ Driver Code Starts

#include <bits/stdc++.h>

using namespace std;

pair<int, int> getFloorAndCeil(int arr[], int n, int x);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        auto ans = getFloorAndCeil(arr, n, x);
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}

// } Driver Code Ends


pair<int, int> getFloorAndCeil(int v[], int n, int x) {
    // code here
    sort(v,v+n) ;
    int l = 0 , r = n-1 , res = -1 ;
    while(l<=r){
        int mid = l+ (r-l)/2 ;
        if(v[mid]==x){
            res= v[mid] ;
            break ;
        }
        else if(v[mid]<x){
            res = v[mid] ;
            l = mid + 1 ;
        }
        else{
            r = mid-1 ;
        }
    }
    int floor = res ;
    l = 0 , r = n-1 , res = -1;
    while(l<=r){
        int mid = l+ (r-l)/2 ;
        if(v[mid]==x){
            res= v[mid] ;
            break ;
        }
        else if(v[mid]<x){
            l = mid + 1 ;
        }
        else{
            res = v[mid] ;
            r = mid-1 ;
        }
    }
    int ceil = res ;
    return {floor,ceil} ;
}