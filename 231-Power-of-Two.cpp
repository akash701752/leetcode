class Solution {
public:
    bool isPowerOfTwo(int n) 
    {
        if(n==1 || n==2 || n==4 || n==8){
            return true ;
        }
        double num , i ;
        for(i=4;i<=sqrt(n);i++)
        {
            num = pow(2,i) ;
            if(num==n){
                return true ;
            }
        }
        return false ;
    }
};
