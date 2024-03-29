class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        int maxi=nums[0];
        for(int i=1;i<n;i++){
            maxi=max(nums[i],maxi);
        }
        long long ans=0;
        deque<int> dq;
        int prev=-1;
        for(int i=0;i<n;i++){
            if(nums[i]==maxi){
                dq.push_back(i);
            }
            if(dq.size()==k){
                int b=dq.back();
                int a=dq.front();
                ans+=(n-b)*1ll*(a-prev);
                prev=a;
                dq.pop_front();
            }
        }
        return ans;
    }
};
