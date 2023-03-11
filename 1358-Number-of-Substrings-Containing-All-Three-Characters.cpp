class Solution {
public:
    // void solve(string in,string op,int &ans)
    // {
    //     if(in.length()==0){
    //         string temp = op ;
    //         int a = count(temp.begin(),temp.end(),'a');
    //         int b = count(temp.begin(),temp.end(),'b');
    //         int c = count(temp.begin(),temp.end(),'c');
    //         if(a>0 && b>0 && c>0){
    //             ans++;
    //         }
    //         return ;
    //     }
    //     string op1 = op ;
    //     string op2 = op ;
    //     //op1.push_back(in[0]);
    //     op2.push_back(in[0]);
    //     in.erase(in.begin()+0);
    //     solve(in,op1,ans) ;
    //     solve(in,op2,ans) ;
    // }
    int numberOfSubstrings(string s) {
        // string op = "" ;
        // int ans = 0 ;
        // solve(s,op,ans) ;
        // return ans ;
        int cnt=0, j=0;
        vector<int>v(3, 0);
        for(int i=0; i<s.size(); i++){
            v[s[i]-'a']++;
            while(v[0] && v[1] && v[2]){
                cnt+=s.size()-i;
                v[s[j]-'a']--;
                j++;
            }
        }
        return cnt;
    }
};
