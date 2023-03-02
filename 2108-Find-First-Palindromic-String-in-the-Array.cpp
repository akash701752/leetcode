class Solution {
public:
    bool check(string s,int i,int j){
        while(i<j){
            if(s[i]!=s[j]){
                return false ;
            }
            i++;
            j--;
        }
        return true ;
    }
    string firstPalindrome(vector<string>& words) {
        string ans ;
        for(auto s : words){
            if(check(s,0,s.length()-1)==true){
                ans = s ;
                break ;
            }
        }
        return ans ;
    }
};
