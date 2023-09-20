class Solution {
public:
    bool isPalindrome(string s) {
        string ans ;
        for(auto x:s){
            if(isalpha(x)){
                if(x>='A' && x<='Z'){
                    ans.push_back(x+32);
                }
                else{
                    ans.push_back(x);
                }
            }
            else if(isdigit(x)){
                ans.push_back(x);
            }
        }
        int i=0 , j = ans.size() -1;
        while(i<j){
            if(ans[i]!=ans[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
