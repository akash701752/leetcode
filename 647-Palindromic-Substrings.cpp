// class Solution {
// public:
//     bool isPalindrome(string s,int i,int j){
//         while(i<j){
//             if(s[i]!=s[j]){
//                 return false;
//             }
//         }
//         return true ;
//     }
//     int countSubstrings(string s) {
        
//     }
// };
class Solution {
public:
    int func(const std::string& s, const size_t len, const size_t i, const size_t j) {
        if(i == 0 || j == len) return 0;
        if(s[i-1] == s[j+1]) {
            return func(s, len, i-1, j+1) + 1;
        }
        return 0;
    }
    
    int countSubstrings(string s) {
        const size_t len = s.length();
        if(len > 1000) return -1;
        int count = 0;
        for(size_t i = 0; i < len; ++i) {
            ++count;
            if(i+1 < len && s[i] == s[i+1]) {
                ++count;
                count += func(s, len, i, i+1);
            }
            count += func(s, len, i, i);
        }
        
        return count;
    }
};
