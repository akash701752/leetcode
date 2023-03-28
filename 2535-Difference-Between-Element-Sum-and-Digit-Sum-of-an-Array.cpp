class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int sum = 0 , d_sum = 0 ;
        for(auto n: nums){
            sum += n ;
            string num = to_string(n) ;
            for(auto ch : num){
                string s = "" ;
                s+= ch ;
                d_sum += stoi(s) ;
            }
        }
        return abs(sum-d_sum) ;
    }
};
