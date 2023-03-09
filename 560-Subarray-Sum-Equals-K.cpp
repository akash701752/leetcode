class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count= 0 , n = nums.size() , i , sum = 0;
        unordered_map<int,int> mp ;
        for(i=0;i<n;i++)
        {
            sum += nums[i] ;
            int key = sum - k ;
            if(sum==k){
                count++ ;
            }
            if(mp.find(key)!=mp.end()){
                count = count + mp[key];
            }
            if(mp.find(sum)!=mp.end()){
                mp[sum] ++;
            }
            else{
                mp[sum] = 1 ;
            }
        }
        return count ;
    }
};
