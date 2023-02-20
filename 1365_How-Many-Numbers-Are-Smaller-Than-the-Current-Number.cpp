class Solution {
public:
    int binarySearch(vector<int> v,int target,int n){
        int l =0 , r = n-1 ;
        while(l<=r){
            int mid = l+ (r-l)/2 ;
            if(v[mid]==target){
                while(mid>0 && v[mid-1]==v[mid]){
                    mid--;
                }
                return mid ;
            }
            else if(v[mid]<target){
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }

        return l;
    }
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> res ;
        vector<int> v = nums ;
        sort(v.begin(),v.end());
        int i , n= nums.size() ;
        for(i=0;i<n;i++){
            int ind = binarySearch(v,nums[i],n) ;
            res.push_back(ind) ;
        }
        return res;
    }
};
