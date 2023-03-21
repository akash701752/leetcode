class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end()) ;
        int ind = 0 , sum = 0 , i = 0 , n = nums.size() ;
        while(ind<n && k>0){
            if(nums[ind]<0){
                nums[ind] = -nums[ind] ;
                ind++ ;
                k-- ;
            }
            else{
                break ;
            }
        }
        sort(nums.begin(),nums.end()) ;
        for(i=1;i<n;i++){
            sum += nums[i];
        }
        if(k%2==0){
            sum += nums[0] ;
        }
        else{
            sum -= nums[0] ;
        }
        return sum ;
    }
};
