class Solution {
public:
      double myPow(double x, int n) {
        if(n == 0){
            return 1;
        }else if(x == 0){
            return 0;
        }
        int sign = 1;
        long long int tmp = n;
        if(tmp < 0){
            tmp = -tmp;
            sign = -1;
        }
        double ans = 1;
        while(tmp > 0){
            if(tmp & 1){
                ans =  ans * x;
            }
            x *= x;
            tmp >>= 1;
        }
        if(sign == 1){
            return ans;
        }else{
            return 1 / ans;
        }
    }
};
