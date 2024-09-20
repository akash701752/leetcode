class Solution {
public:
bool checkPalindrome(string s, int i, int j)
{
    for(;i<j;i++,j--)
    {
        if(s[i]!=s[j])
        return false;
    }
    return true;
}

string shortestPalindrome(string s) 
{
    int i,n=s.size();
    vector<int> v(n+1,0);
    for(i=1;i<=n;i++)
    {
        v[i]=v[i]+v[i-1]+s[i-1]-'a';
    }
    string ans;
    for(i=n;i>=1;i--)
    {
        if((i%2==0 and v[i/2]==v[i]-v[i/2]) or (i%2!=0 and v[i/2]==v[i]-v[i/2+1]))
        {
            if(checkPalindrome(s,0,i-1))
            {
                ans=s.substr(i);
                reverse(ans.begin(),ans.end());
                break;
            }
        }
    }
    return ans+s;
}
};
