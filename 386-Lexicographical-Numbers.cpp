class Solution {
public:
   void solve(int curr, int n, vector<int>&res){
        if(curr>n)
        return;
        res.push_back(curr);

        for(int a=0;a<=9;a++){
            int newNum = (curr*10) + a;
            if(newNum>n) return;
            solve(newNum , n ,res);
        }
   }
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        for(int startNum=1;startNum<=9;startNum++){
            solve(startNum , n ,res);
        }
        return res;
    }
};
