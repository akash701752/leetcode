class Solution {
public:
    void per(vector<int>& nums,int pos,vector <vector<int>> &res)
    {
        if(pos>=nums.size()) {
            res.push_back(nums) ;
            return ;
        }
        for(int i=pos;i<nums.size();i++)
        {
            swap(nums[i],nums[pos]) ;
            per(nums,pos+1,res) ;
            swap(nums[i],nums[pos]) ;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector <vector<int>> res ;
        per(nums,0,res) ;
        return res ;
    }
};
