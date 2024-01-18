class Solution {
public:
    int fibo(int n){
        int first = 0 , second = 1 , next ;
        for(int i=1;i<=n;i++){
            next = first + second ;
            first = second ;
            second = next ;
        }
        return next ;
    }
    int climbStairs(int n) {
        if(n==1){
            return n ;
        }
        return fibo(n) ;
    }
};
