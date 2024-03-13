class Solution {
public:
    int pivotInteger(int n) {
        int total =0;
        
        total = (n*(n+1))/2 ;
        int presum=0;
        
        for(int i=1; i<=n; i++){
            presum += i; 
            if((total - presum + i) == presum){
                return i;
            }
        }
        return -1;
    }
};
