class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        int i=0,j=2;
        while(j<n){
            if(nums[j]-nums[i]>k) return {};
            else{
                vector<int> temp;
                while(i<=j){
                    temp.push_back(nums[i]);
                    i++;
                }
                ans.push_back(temp);
                j+=3;
            }
        }
        return ans;
    }
};
