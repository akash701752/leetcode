class Solution {
public:
    
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
       if(source==target) return 0;
        
        vector<vector<int>> v(1000000);
        for(int i=0;i<routes.size();i++)
            for(int j=0;j<routes[i].size();j++)
                v[routes[i][j]].push_back(i);
        
        
        queue<int> q;
         
        for(auto &n:v[source])
            q.push(n);
        
        int ans=1;
        set<int> st;
        
        while(!q.empty()){
            
            int sz=q.size();
            
            while(sz--){
                int p=q.front();
                q.pop();
                
                if(st.count(p))
                    continue;
                
                for(auto &nn:routes[p]){
                    if(nn==target) 
                        return ans;
                    for(auto& n:v[nn]){
                        q.push(n);
                    }
                }
                st.insert(p);
  
            }
            ans++;
        }
        
        return -1;
           
    }
};
