class Solution {
public: 
    bool isPossible(vector<int>&nums,int mid,int k,int m){
        int i=0,n=nums.size(),count=0;
        
        while(i+k-1<n) //For Every window of k from starting from any index i.
        {
            int mx=INT_MIN;
            int index=-1;
            for(int j=i;j<=i+k-1;j++) {
                if(nums[j]>=mx)
                    mx=nums[j],index=j;
            }
            if(mx>mid) 
                i=index+1; 
            else{
                i=i+k; 
                count++; 
            }
        }
        
        return count>=m?1:0; //If count is greater than m means it is possible ans.
    }
    int minDays(vector<int>& nums, int m, int k) {
        int low=*min_element(nums.begin(),nums.end()); //Lowest days we require,
        int high=*max_element(nums.begin(),nums.end()); //Highest days we require
        
        int ans=-1;
        
        while(low<=high) {
            int mid=low+(high-low)/2;
            
            if(isPossible(nums,mid,k,m)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        
        return ans;
    }
};
