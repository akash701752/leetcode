class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>> pq;
        if(a>0){
            pq.push({a,'a'});
        }
        if(b>0){
            pq.push({b,'b'});
        }
        if(c>0){
            pq.push({c,'c'});
        }
        string ans = "" ;
        while(pq.size()>0)
        {
            int freq1 = pq.top().first ;
            char ch1 = pq.top().second ;
            pq.pop() ;
            int min1 = min(2,freq1) ;
            ans += string(min1,ch1) ;

            freq1 = freq1 - min1 ;
            if(pq.size()>0)
            {
                int freq2 = pq.top().first ;
                char ch2 = pq.top().second ;
                pq.pop() ;
                int min2 = min(freq2,2) ;
                if(freq2>freq1){
                    ans += string(min2,ch2);
                    freq2 = freq2 - min2 ;
                }
                else{
                    ans += ch2 ;
                    freq2 -- ;
                }
                if(freq1>0){
                    pq.push({freq1,ch1}) ;
                }
                if(freq2>0){
                    pq.push({freq2,ch2}) ;
                }
            }
        }
        return ans ;
    }
};
