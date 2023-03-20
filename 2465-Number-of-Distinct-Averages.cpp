class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        set<float> st ;
        sort(nums.begin(),nums.end()) ;
        while(nums.size()>0)
        {
            int n = nums.size() ;
            float a = nums[0] , b = nums[n-1] ;
            nums.erase(nums.begin()+n-1) ;
            nums.erase(nums.begin()+0) ;
            st.insert((a+b)/2.0) ;
        }
        return st.size() ;
    }
};
