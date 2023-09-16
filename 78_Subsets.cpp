class Solution {
public:
    void help(vector<vector<int>> &res,vector<int> in,vector<int> op){
        if(in.size()==0){
            res.push_back(op) ;
            return ;
        }
        vector<int> op1 = op ;
        vector<int> op2 = op ;

        op2.push_back(in[0]) ;
        in.erase(in.begin()+0) ;
 
        help(res,in,op1) ;
        help(res,in,op2) ;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res ;
        vector<int> in = nums ;
        vector<int> op ;
        help(res,in,op);
        return res;
    }
};
