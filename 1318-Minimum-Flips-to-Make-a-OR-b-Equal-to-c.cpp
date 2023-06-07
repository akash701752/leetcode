class Solution {
public:
    int minFlips(int a, int b, int c) {
        int count=0;
        while(c) {
            if((c&1)!=(a&1) && (c&1)!=(b&1)){
                if(c&1)
                    count++;
                else
                    count+=2;
            }
            else if((c&1)!=(a&1)){
                if((c&1)==0)
                    count++;
            }
            else if((c&1)!=(b&1)) {
                if((c&1)==0)
                    count++;
            }
            c=c>>1;
            a=a>>1;
            b=b>>1;
        }
        while(a){
            count+=a&1;
            a=a>>1;
        }
        while(b){
            count+=b&1;
            b=b>>1;
        }
        return count;
    }
};
