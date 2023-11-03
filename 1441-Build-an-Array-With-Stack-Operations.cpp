class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> res;
        int size = target.size() , i , ind;
        i = 0 , ind = 1 ;
        while(i<size){
            int num = target[i] ;
            if(num==ind){
                res.push_back("Push");
                i++;
            }
            else{
                res.push_back("Push");
                res.push_back("Pop");
            }
            ind++;
        }
        return res;
    }
};
