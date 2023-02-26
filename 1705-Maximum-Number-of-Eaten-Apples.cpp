class Solution {
public:
    typedef pair<int,int> p ;
    int eatenApples(vector<int>& apples, vector<int>& days) {
        // priority_queue<p,vector<p>,greater<p>> pq ;
        priority_queue<p> pq ;
        int count = 0 , d= 1 , n = apples.size() , i =0  ;
        if(n<2){return apples[0] ;}
        while(i<n || pq.size()>0)
        {
            if(i<n){
                pq.push({-(d+ days[i]),apples[i]}) ;  
            }
            i++ ;
            while(pq.size()>0 && -pq.top().first <=d){
                pq.pop() ;
            }
            if(pq.size())
            {
                p a = pq.top() ;
                pq.pop();
                a.second -- ;
                count ++ ;
                if(a.second>0){
                    pq.push(a) ;
                }
            }
            d++ ;
        }
        return count ;
    }
};
