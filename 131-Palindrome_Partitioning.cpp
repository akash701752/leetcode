class Solution {
public:
    vector<vector<string>> partition(string s) {
        string tmp;
        vector<string> out;
        vector<vector<string>> res;
        dfs(s,0,tmp,out,res);
        return res;
    }
private:
    void dfs(string s,int idx,string tmp,vector<string>&out,vector<vector<string>>&res)
    {
        if(idx==s.size())
        {
            res.push_back(out);
            return;
        }
        for(int i = idx;i<s.size();i++)
        {
            tmp+=s[i];
            if(isPalindrome(tmp))
            {
                out.push_back(tmp);
                dfs(s,i+1,"",out,res);
                out.pop_back();
            }
        }
    }
    bool isPalindrome(string tmp)
    {
        int left = 0,right = tmp.size()-1;
        while(left<right)
        {
            if(tmp[left]!=tmp[right]) return false;
            left++;
            right--;
        }
        return true;
    }
};
