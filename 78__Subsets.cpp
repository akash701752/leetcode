// class Solution {
// public:
//     void solve<vector<vector<int>> &nums,vector<int> &in, vector<int> &op>{
//         if(in.size()==0){
//             res.push_back(op) ;
//             return ;
//         }
//         vector<int> op1 = in ;
//         vector<int> op2 = op ;
//         in.erase(in.begin()+0) ;

//         solve(res,op)
//     }
//     vector<vector<int>> subsets(vector<int>& nums) {
//         vector<vector<int>> res ;
//         vector<int> in = nums ;
//         vector<int> op ;
//         solve(res,in,op);
//         return res;
//     }
// };

class Solution {
public:
    //DP 8ms
    //each time, we add the current number to all the subsets
    //then combine them to all the previous subsets
    /*
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        ret.push_back(vector<int>());
        vector<vector<int>> sub;
        for(int i = 0; i < nums.size(); ++i){
            sub = ret;
            for(auto& j : sub){
                j.push_back(nums[i]);//add
            }
            ret.insert(ret.end(), sub.begin(), sub.end());//combine
        }
        return ret;
    }
    */
    //recursive 8ms
    void generate(int depth, vector<int>& path, vector<vector<int>>& ans, vector<int>& nums){
        ans.push_back(path);
        for(int i = depth; i < nums.size(); ++i){
            path.push_back(nums[i]);
            generate(i + 1, path, ans, nums);
            path.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;
        generate(0, path, ans, nums);
        return ans;
    }
};
