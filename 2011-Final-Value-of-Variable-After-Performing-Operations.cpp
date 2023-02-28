class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int n = operations.size() ,  i ;
        int x = 0 ;
        for(i=0;i<n;i++){
            string s = operations[i] ;
            if(s=="++X" ){
                ++x ;
            }
            else if(s=="--X" ){
                --x ;
            }
            else if(s=="X++" ){
                x++ ;
            }
            else if(s=="X--" ){
                x-- ;
            }
        }
        return x ;
    }
};
