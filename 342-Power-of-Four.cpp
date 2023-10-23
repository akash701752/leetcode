class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n==1 || n== 4 || n==16){
            return true ;
        }
        double num , i ;
        for(i=3;i<=sqrt(n);i++)
        {
            num = pow(4,i) ;
            cout<<num <<" ";
            if(num==n){
                return true ; 
            }
        }
        return false ;
    }
};
