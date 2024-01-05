class Solution {
public:
    void bSearch(vector<int> &res,int key){
        int start = 0 , end = res.size()-1 , ind = 0 ;
        while(start<=end){
            int mid = start + (end-start)/2 ;
            if(key<res[mid]){
                ind = mid ;
                end = mid-1;
            }
            else if(key>res[mid]){
                start = mid+1;
            }
            else{
                return;
            }
        }
        res[ind] = key ;
    }
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()==0){
            return 0 ;
        }
        vector<int> res ;
        res.push_back(nums[0]);
        int i , n = nums.size();
        for(i=1;i<n;i++){
            if(nums[i]>res[res.size()-1]){
                res.push_back(nums[i]);
            }
            else{
                bSearch(res,nums[i]);
            }
        }
        return res.size() ;
    }
};
