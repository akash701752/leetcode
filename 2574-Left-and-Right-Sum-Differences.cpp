class Solution {
public:
    vector<int> leftRigthDifference(vector<int>& nums) {
        int n = nums.size() , i ;
        vector<int> left(n) , right(n) ;
        left[0] = 0 , right[n-1] = 0 ;
        for(i=0;i<n-1;i++){
            left[i+1] = left[i]+ nums[i] ;
        }
        for(i=n-1;i>0;i--){
            right[i-1] = right[i] + nums[i] ;
        }
        vector<int> ans(n) ;
        for(i=0;i<n;i++){
            ans[i] = abs(left[i]-right[i]) ;
        }
        return ans ;
    }
};
