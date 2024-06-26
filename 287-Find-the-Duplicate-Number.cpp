class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size() ;
        vector<int> v(n+1,0) ;
        for(int i=0;i<n;i++){
            v[nums[i]]++;
        }
        for(int i=0;i<n+1;i++){
            if(v[i]>1){
                return i;
            }
        }
        return 0;
    }
};
