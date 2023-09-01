class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> v(n+1);
        cout<<n <<" ";
        for(int i=0;i<=n;i++){
            int num = i ;
            int count = 0 ;
            while(num){
                count += num & 1 ;
                num = num>>1 ;
            }
            v[i]=count;
        }
        return v;
    }
};
