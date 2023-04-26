class Solution {
public:
    int addDigits(int n) 
    {
       if(n<10){
           return n ;
       } 
       int sum , i , rem  , num ;
        sum = num = n ;
        while(sum>9)
        {
            sum = 0 ;
            while(num>0)
            {
                rem = num%10 ;
                sum += rem ;
                num = num/10 ;
            }
            num = sum ;
        }
        return sum ;
    }
};
