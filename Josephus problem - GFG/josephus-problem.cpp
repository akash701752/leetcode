//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
/*You are required to complete this method */

class Solution
{
    public:
    void solve(vector<int> in,int k, int ind,int *ans){
        if(in.size()==1){
            (*ans) = in[0] ;
            return;
        }
        int index = (ind+k)%in.size() ;
        in.erase(in.begin()+index) ;
        
        solve(in,k,index,ans);
    }
    int josephus(int n, int k)
    {
       //Your code here
       vector<int> v(n) ;
       for(int i=0;i<n;i++){
           v[i] = i+1;
       }
       k = k- 1 ;
       int ans ;
       solve(v,k,0,&ans) ;
       return ans;
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