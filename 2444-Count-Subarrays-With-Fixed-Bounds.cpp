class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans= 0 ;
        bool minFound = false, maxFound = false ;
        int start, minStart , maxStart , n = nums.size() , i;
        start = minStart = maxStart = 0 ;
        for(i=0;i<n;i++)
        {
            int num = nums[i];
            if(num< minK || num>maxK){
                minFound = maxFound = false ;
                start = i+1;
            }
            if(num==minK){
                minFound = true ;
                minStart = i ;
            }
            if(num==maxK){
                maxFound = true ;
                maxStart = i ;
            }
            if(minFound && maxFound){
                ans += min(minStart,maxStart) - start +1;
            }
        }
        return ans ;
    }
};
