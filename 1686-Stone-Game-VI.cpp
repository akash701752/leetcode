class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        priority_queue<pair<int,pair<int,int>>> pq ;
        int n = aliceValues.size() , i ;
        for(i=0;i<n;i++){
            pq.push({aliceValues[i]+bobValues[i],{aliceValues[i],bobValues[i]}}) ;
        }
        int bob = 0 , alice = 0   ;
        i=  0 ;
        while(pq.size()>0){
            if(i%2==0){
                alice += pq.top().second.first ;
            }
            else{
                bob   += pq.top().second.second ;
            }
            pq.pop() ;
            i++ ;
        }
        if(alice>bob){
            return 1 ;
        }
        else if(alice==bob){
            return 0 ;
        }
        else{
            return -1; 
        }
    }
};
