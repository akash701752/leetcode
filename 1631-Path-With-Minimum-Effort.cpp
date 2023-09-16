class Solution {
public:
    bool safe(int i,int j,int n,int m)
    {
        if(i>=0 && i<n && j>=0 && j<m)
        {
            return true;
        }
        return false;
    }
    
   
    
    typedef pair<int,pair<int,int>>ip;
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        int ans=INT_MAX;
        priority_queue<ip,vector<ip>,greater<ip>>pq;
        pq.push({0,{0,0}});
        vector<vector<int>>dis(n,vector<int>(m,INT_MAX-1));
        int r[] = { -1, 0, 0, 1 }; 
        int c[] = { 0, -1, 1, 0 }; 
        dis[0][0]=0;
        while(pq.empty()!=true)
        {
            auto top=pq.top();
            int d=top.first;
            int i=top.second.first;
            int j=top.second.second;
            pq.pop();
            for(int k=0;k<4;k++)
            {
                if( safe(i+r[k],j+c[k],n,m))
                {
                    int newdis=max(d,abs(heights[i][j]-heights[i+r[k]][j+c[k]]));
                    if(dis[i+r[k]][j+c[k]]>newdis )
                    {
                        dis[i+r[k]][j+c[k]]=newdis;
                        pq.push({newdis,{i+r[k],j+c[k]}});
                    }
                }
            }
           
        }
       
        return dis[n-1][m-1];
      
        
    }
};
