class Solution {
public:
    int getMin(vector<int> &v){
        int n = v.size(), l , r , res =-1 ;
        l = 0 , r = n-1 ;
        while(l<=r){
            if(v[l]<v[r]){
                return l ;
            }
            int mid = l+ (r-l)/2 ;
            int prev = (mid-1+n)%n;
            int next = (mid+1)%n ;
            if(v[mid]<=v[prev] && v[mid]<=v[next]){
                res = mid;
                break ;
            }
            else if(v[0]<=v[mid]){
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        return res;
    }
    int binarySearch(vector<int> &v,int left,int right, int key){
        int n = v.size(), l , r , res =-1 ;
        l = left , r = right-1 ;
        while(l<=r){
            int mid = l+ (r-l)/2 ;
            if(v[mid]==key){
                res = mid;
                break ;
            }
            else if(v[mid]<key){
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        return res;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size() , minInd;
        if(n==2){
            if(nums[0]<nums[1]){
                minInd = 0;
            }
            else{
                minInd = 1;
            }
        }
        else{
            minInd = getMin(nums);
        }
        if(nums[minInd]==target){
            return minInd ;
        }
        int find1 = binarySearch(nums,0,minInd,target);
        int find2 = binarySearch(nums,minInd+1,nums.size(),target);
        if(find1!=-1){
            return find1;
        }
        else {
            return find2;
        }
    }
};
