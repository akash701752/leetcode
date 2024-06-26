//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


// } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    void solve(int open,int close,string op,vector<string> &res)
    {
        if(open ==0 && close==0){
            res.push_back(op) ;
            return ;
        }
        if(open!=0){
            string op1 = op ;
            op1.push_back('(');
            solve(open-1,close,op1,res);
        }
        if(close>open){
            string op2 = op ;
            op2.push_back(')');
            solve(open,close-1,op2,res);
        }
    }
    vector<string> AllParenthesis(int n) 
    {
        // Your code goes here 
        int open = n , close = n ;
        string op = "" ;
        vector<string> res ;
        solve(open,close,op,res);
        return res ;
    }
};

//{ Driver Code Starts.


int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 

// } Driver Code Ends