class Solution {
public:
    void solve(string op,string in,vector<string> &ans)
    {
        if(in.length()==0){
            ans.push_back(op) ;
            return ;
        }
        string op1 = op ;
        string op2 = op ;
        if(isalpha(in[0])){
            op1.push_back(tolower(in[0])) ;
            op2.push_back(toupper(in[0])) ;
            in.erase(in.begin()+0) ;
            solve(op1,in,ans) ;
            solve(op2,in,ans) ;
        }
        else{
            op1.push_back(in[0]);
            in.erase(in.begin()+0);
            solve(op1,in,ans) ;
        }
    }
    vector<string> letterCasePermutation(string s) {
        vector<string> ans ;
        string op = "" ;
        solve(op,s,ans) ;
        return ans ;
    }
};
