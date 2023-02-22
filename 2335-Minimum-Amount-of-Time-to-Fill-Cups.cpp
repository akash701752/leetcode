class Solution {
public:
    int fillCups(vector<int>& amount) {
        priority_queue<int> pq ;
        for(int i=0;i<3;i++){
            if(amount[i]>0){
                pq.push(amount[i]) ;
            }
        }
        int sec = 0 ;
        while(pq.size()>1){
            int a = pq.top() ;
            pq.pop() ;
            int b = pq.top() ;
            pq.pop() ;
            a-- ;
            b-- ;
            if(a>0){
                pq.push(a) ;
            }
            if(b>0){
                pq.push(b);
            }
            sec++ ;
        }
        if(pq.size()>0){
            sec += pq.top() ;
        }
        return sec ;
    }
};
