class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
       long long count = 0 , ans = 0 ;
       for(auto n: nums){
           if(n==0){
               count++ ;
           }
           else{
               ans += (count*(count+1))/2 ;
               count = 0 ;
           }
       } 
       if(count!=0){
           ans += (count*(count+1))/2 ;
       }
       return ans ;
    }
};
