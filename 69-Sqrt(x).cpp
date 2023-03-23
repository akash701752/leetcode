class Solution {
public:
    int mySqrt(int x) {
        if(x == 1){
            return 1;
        }
        int low = 0;
        int high = x;
        while(low < high - 1){  
            int mid = low + (high - low)/2;
            if(mid == x / mid){
                return mid; 
            }
            else if(mid > x / mid){
                high = mid; 
            } 
            else{
                low = mid; 
            }
        }
        return low;
    }
};
