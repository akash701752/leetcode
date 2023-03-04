class Solution {
public:
    int percentageLetter(string s, char letter) {
        int c = count(s.begin(),s.end(),letter) ;
        int n = s.length() ;
        return (c*100)/n ;
    }
};
