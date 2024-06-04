class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.length() , i ;
        if(n<=1){
            return n;
        }
        unordered_map<int,int> mp ;
        for(i=0;i<n;i++){
            mp[s[i]]++ ;
        }
        int ans = 0 , carry = 0 ;
        for(auto it : mp){
            if(it.second%2==0){
                ans += it.second ;
            }
            else{
                ans += it.second -1;
                carry = 1 ; // middle
            }
        }
        return ans + carry;
    }
};
