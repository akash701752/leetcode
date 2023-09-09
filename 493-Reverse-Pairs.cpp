class Solution {
public:
    void merge(vector<int>& nums,int low,int mid,int high){
        vector<int> v ;
        int i = low , j = mid+1;
        while(i<=mid && j<=high){
            if(nums[i]<=nums[j]){
                v.push_back(nums[i]);
                i++;
            }
            else{
                v.push_back(nums[j]);
                j++;
            }
        }
        while(i<=mid){
            v.push_back(nums[i]);
            i++;
        }
        while(j<=high){
            v.push_back(nums[j]);
            j++;
        }
        for(int ind=low,k=0;i<v.size(),ind<=high;k++,ind++){
            nums[ind] = v[k];
        }
        return;
    }
    int countPairs(vector<int>& nums,int low,int mid,int high){
        int count = 0 ;
        int right = mid+1 ;
        for(int k=low;k<=mid;k++){
            while(right<=high && (nums[k]/2.0 >nums[right])){
                right++;
            }
            count += (right-(mid+1));
        }
        return count ;
    }
    int mergeSort(vector<int>& nums,int low,int high){
        int count = 0 ;
        if(low>=high){
            return count;
        }
        int mid = low+ (high-low)/2;
        count += mergeSort(nums,low,mid);
        count += mergeSort(nums,mid+1,high);
        count += countPairs(nums,low,mid,high);
        merge(nums,low,mid,high);
        return count;
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size() ;
        int ans = mergeSort(nums,0,n-1);
        return ans;
    }
};
