class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0 ; 
        for(auto n:nums){
            string num = to_string(n) ;
            if(num.size()%2==0){
                count++ ;
            }
        }
        return count ;
    }
};
