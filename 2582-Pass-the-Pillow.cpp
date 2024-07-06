class Solution {
public:
    int passThePillow(int n, int time) {
        int rem=time%(n-1);
        if((time/(n-1))%2!=0){
            return n-rem;
        }
        return 1+rem;
    }
};
