class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        // sort(nums.begin(),nums.end());
        int ma=*max_element(nums.begin(),nums.end());
        vector<int>v(ma+1);
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                int s=abs(nums[j]-nums[i]);
                v[s]++;
            }
        }
        for(int j=0;j<ma+1;j++){
            int i=v[j];
            if(i>=k){
                return j;
            }else{
                k-=i;
            }
        }
        return -1;
    }
};
