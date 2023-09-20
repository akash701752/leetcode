class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        
        unordered_map<int,int> um;
        int n = nums.size();
        if(nums[n-1]==x)
            return 1;
        int mini=INT_MAX,step = 0;
        int sum=0;
        for(int i=nums.size()-1;i>=0;i--)
        {
            sum+=nums[i];
            step++;
            if(sum==x)
                mini = min(mini,step);
            um[sum]=step;
        }
        sum=0;
        step=0;
        for(int i=0;i<n;i++)
        {
            sum=sum+nums[i];
            step=i+1;
            if(sum==x)
            {
                mini = min(mini,step);
                break;
            }
            if(um.count(x-sum))
            {   
                if(step+um[x-sum]<=n)
                    mini=min(mini,step+um[x-sum]);
            }
        }
        if(mini == INT_MAX)
            return -1;
        return mini;
    }
};
