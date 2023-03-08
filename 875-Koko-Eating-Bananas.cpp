class Solution {
public:
    bool canEatInTime(vector<int>& piles, int k, int h){
        long int hours = 0 ;
        for(auto n : piles)
        {
            int num = n/k ;
            hours += num ;
            if(n%k>0){
                hours++;
            }
        }
        return hours <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int sum = 0 ;
        int left = 1 , right = 1e9 ;
        while(left<=right){
            int mid = left + (right-left)/2 ;
            if(canEatInTime(piles,mid,h)==true){
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        return left ;
    }
};
