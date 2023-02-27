class Solution {
public:
    int maximumScore(int a, int b, int c) {
        priority_queue<int> maxH ;
        if(a>0){
            maxH.push(a) ; 
        }
        if(b>0){
            maxH.push(b) ;
        }
        if(c>0){
            maxH.push(c) ;
        }
        int ans = 0  ;
        while(maxH.size()>1)
        {
            int mx = maxH.top() -1;
            maxH.pop() ;
            int mn = maxH.top() -1 ;
            maxH.pop() ;
            if(mx>0 ){
                maxH.push(mx) ;
            }
            if(mn>0){
                maxH.push(mn) ;  
            }
            ans ++;    
        }
        return ans ;
    }
};
