class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> res ;
        int i ,j , n= nums.size();
        for(i=0;i<n;i++){
            int count = 0 , ele = nums[i];
            for(j=0;j<n;j++){
                if(i!=j && nums[j]<ele){
                    count++ ;
                }
            }
            res.push_back(count) ;
        }
        return res;
    }
};
