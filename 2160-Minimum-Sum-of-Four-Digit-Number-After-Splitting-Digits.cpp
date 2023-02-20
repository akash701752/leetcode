class Solution {
public:
    int minimumSum(int num) {
        int n =num ;
        vector<int> v ;
        while(n>0){
            v.push_back(n%10);
            n /= 10;
        }
        sort(v.begin(),v.end()) ;
        int num1 = v[0]*10 + v[2] ;
        int num2 = v[1]*10 + v[3] ;
        return num1+ num2 ;
    }
};
