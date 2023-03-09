class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size() , i , size = 0 , sum = 0;
        for(i=0;i<n;i++){
            if(nums[i]==0){
                nums[i]= -1;
            }
        }
        unordered_map<int,int> mp ;
        for(i=0;i<n;i++){
            sum += nums[i] ;
            if(sum==0){
                size = max(size,i+1);
            }
            if(mp.find(sum)!=mp.end()){
                size = max(size,i-mp[sum]);
            }
            else{
                mp[sum] = i ;
            }
        }
        return size ;
    }
};
