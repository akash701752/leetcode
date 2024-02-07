class Solution {
public:
    
    string frequencySort(string s) {
        unordered_map<char,int> mp ;
        int n = s.length() , i ;
        for(i=0;i<n;i++){
            mp[s[i]]++ ;
        }
        string ans ;
        priority_queue<pair<int,char>> pq ;
        for(auto it : mp){
            pq.push({it.second,it.first}) ;
        }
        while(pq.size()>0)
        {
            int f = pq.top().first ;
            while(f-->0){
                ans.push_back(pq.top().second) ;
            }
            pq.pop() ;
        }
        return ans ;
    }
};
