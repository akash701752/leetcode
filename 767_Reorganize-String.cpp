class Solution {
public:
    string reorganizeString(string s) {
       unordered_map<char,int> mp ;
       int i , n = s.length() ;
       for(i=0;i<n;i++){
           mp[s[i]]++ ;
       } 
       priority_queue<pair<int,char>> pq ;
       for(auto it : mp){
           pq.push({it.second,it.first}) ;
       }
       string ans = "" ;
       while(pq.size()>0)
        {
            int freq1 = pq.top().first ;
            char ch1 = pq.top().second ;
            pq.pop() ;
            ans.push_back(ch1) ;
            if(pq.size()!=0){
                int freq2 = pq.top().first ;
                char ch2 = pq.top().second ;
                pq.pop() ;
                ans.push_back(ch2) ;
                freq2-- ;
                if(freq2>0){
                    pq.push({freq2,ch2}) ;
                }    
            }
            freq1-- ;
            if(freq1>0){
                pq.push({freq1,ch1}) ;
            }
        }    
       for(i=1;i<ans.size();i++){
           if(ans[i-1]==ans[i]){
               return "" ;
           }
       }
       return ans ;
    }
};
