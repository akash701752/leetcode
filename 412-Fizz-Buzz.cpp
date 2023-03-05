class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> v(n);
        int i ;
        for(i=1;i<=n;i++){
            if(i%3==0){
                v[i-1] += "Fizz" ;
            }
            if(i%5==0){
                v[i-1] += "Buzz" ;
            }
            if(v[i-1].empty()){
                v[i-1] += to_string(i) ;
            }
        }
        return v ;
    }
};
