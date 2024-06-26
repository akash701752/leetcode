class Solution {
public:
	vector<int> getAverages(vector<int>& nums, int k) {
		int n = nums.size();
		vector<int> res(n, -1);
		if(k * 2 >= n){
			return res;
		}
		long sum = 0;
		for(int i = 0; i <= 2 * k; i++){
			sum += nums[i];
		}
		res[k] = sum / (2 * k + 1);
		int curr = k + 1;
		int l = 0;
		for(int i = 2 *k + 1; i < n; i++){
			sum  = sum + (nums[i] - nums[l++]);
			res[curr++] = sum / (2 * k + 1);
		}
		return res;
	}
};
