class Solution
{
public:
    int minOperations(vector<int>& nums) 
    {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        nums.erase(unique(nums.begin(),nums.end()),nums.end());
        deque<int>dq;
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            dq.push_back(nums[i]);
            while(dq.back()-dq.front()>n-1)
            {
                dq.pop_front();
            }
            ans=max(ans,(int)dq.size());
        }
        return n-ans;
    }
};
