//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
/*You are required to complete this method */

class Solution
{
    public:
    void solve(vector<int> &v,int k,int ind,int &ans){
        if(v.size()==1){
            ans = v[0] ;
            return ;
        }
        ind = (ind+k)%v.size() ;
        v.erase(v.begin()+ind) ;
        solve(v,k,ind,ans) ;
    }
    int josephus(int n, int k)
    {
       //Your code here
       vector<int> v(n) ;
       for(int i=0;i<n;i++){
           v[i] = i+1 ;
       }
       int ans =-1 ,ind = 0 ;
       solve(v,k-1,ind,ans) ;
       return ans ;
    }
};



//{ Driver Code Starts.

int main() {
	
	int t;
	cin>>t;//testcases
	while(t--)
	{
		int n,k;
		cin>>n>>k;//taking input n and k
		
		//calling josephus() function
		Solution ob;
		cout<<ob.josephus(n,k)<<endl;
	}
	return 0;
}
// } Driver Code Ends