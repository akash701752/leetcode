class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> mp;
        for(auto ch : tasks){
            mp[ch]++;
        }
        priority_queue<int> pq;
        for(auto it : mp){
            pq.push(it.second) ;
        }
        int ans = 0 ;
        while(pq.size()>0)
        {
            vector<int> v ;
            int time = 0 ;
            for(int i=0;i<n+1;i++)
            {
                if(pq.size()>0){
                    v.push_back(pq.top()-1) ;
                    pq.pop() ;
                    time++ ;
                }
            }
            for(int i=0;i<v.size();i++){
                if(v[i]!=0){
                    pq.push(v[i]);
                }
            }
            if(pq.size()==0){
                ans += time ;
            }
            else{
                ans += n+1 ; 
            }
        }
        return ans ;
    }
};
