class Solution {
public:
    bool judgeSquareSum(int c) {
        long int r = std::sqrt(c);
        long int res = 0;
        
        if (c <= 2) return true;
        
        for (long int i = 0, j = r; i <= j;) {
            res = i*i + j*j;
            
            if (res == c) {
                return true;
            }
            else if (res > c) {
                j--;
            }
            else {
                i++;
            }
        }
        
        return false;
    }
};
