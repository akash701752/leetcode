class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n=nums.size();
		vector<int> dp(n);
		dp[0]=nums[0];
		deque<int> dq;
		dq.push_back(0);
		for(int i=1;i<nums.size();i++)
		{
			if(i-dq.front()>k)
			{
				dq.pop_front();
			}
			dp[i]=max(nums[i],dp[dq.front()]+nums[i]);
			while(!dq.empty() && dp[i]>=dp[dq.back()])
			{
				dq.pop_back();
			}

			dq.push_back(i);
		}

		return *max_element(dp.begin(),dp.end());

    }
};
