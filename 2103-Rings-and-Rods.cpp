class Solution {
public:
    int countPoints(string rings) {
        vector<int>r(10,0) , g(10,0) , b(10,0);
        int n = rings.length()  , i , ans = 0 ;
        for(i=0;i<n-1;i+=2)
        {
            int ind = rings[i+1] - '0';
            if(rings[i]=='R' && r[ind]!=-1){
                r[ind] = 1 ;
            }
            else if(rings[i]=='G'){
                g[ind] = 1 ;
            }
            else if(rings[i]=='B'){
                b[ind] =1 ;
            }
            if(r[ind]+ g[ind]+ b[ind] ==3 ){
                ans++ ;
                r[ind]= -1;
            }
        }
        return ans ;
    }
};
