//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int partition(vector<int>&arr,int l,int h)
    {
        int pivot = arr[h] , i = l-1 , j ;
        for(j=l;j<h;j++){
            if(arr[j]<pivot){
                i++ ;
                swap(arr[i],arr[j]) ;
            }
        }
        i++ ;
        swap(arr[i],arr[h]) ;
        return i ;
    }
    void quickSort(vector<int>&arr,int l,int h)
    {
        if(l<h)
        {
            int ind = partition(arr,l,h) ;
            quickSort(arr,l,ind-1) ;
            quickSort(arr,ind+1,h) ;
        }
    }
    vector<int> sortArr(vector<int>arr, int n){
    //complete the function here
        quickSort(arr,0,n-1);
        return arr ;
    }
};

//{ Driver Code Starts.
int main(){
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int>s(n);
        for(int i = 0; i < n; i++)
            cin >> s[i];
        Solution ob;
        vector<int>v = ob.sortArr(s, n);
        for(auto i : v)
            cout << i << ' ';
        cout << endl;
    }
return 0;
}


// } Driver Code Ends