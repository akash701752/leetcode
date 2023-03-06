// class Solution {
// public:
//     bool isPalindrome(string s,int i,int j){
//         while(i<j){
//             if(s[i]!=s[j]){
//                 return false;
//             }
//             i++;
//             j--;
//         }
//         return true ;
//     }
//     bool validPalindrome(string s) {
//         int n = s.length() , l , r ;
//         l = -1 , r = n;
//         while(++l < --r)
//         {
//             if(s[l]!=s[r]){
//                 return (isPalindrome(s,l,r+1) || isPalindrome(s,l-1,r) ) ;
//             }
//             // l++ ;
//             // r-- ;
//         }
//         return true ;
//     }
// };
class Solution {
public:
    bool validPalindrome(string s) {
        int l = 0;
        int r = s.length() -1;
        while (l < r) {
            if (s[l] != s[r]) {
                return isPalindrome(s, l, r+1) || isPalindrome(s, l-1, r);
            }
            l++ ;
            r-- ;
        }
        
        return true;
    }
    bool isPalindrome(string s, int l , int r) {
        while (++l < --r) {
            if (s[l] != s[r]) {
                return false;
            }
        }
        return true;
    }
};
