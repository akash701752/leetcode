class Solution {
public:
    int findComplement(int n) {
        int x=n,i=0;
        
        // To iterate over every bit
        while(x!=0){
            // selecting bit to manipulate
            int m = 1<<i;
            // manipulating bit at current position
            n = n^m;
            // To move for next bit
            i++;
            // To stop loop when number becomes zero
            x/=2;
        }

        return n;
    }
};
