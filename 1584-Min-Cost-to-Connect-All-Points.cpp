class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int vertices=points.size();
        vector<vector<pair<int,int>>> graph(points.size());
        for(int i=0;i<points.size();i++){
            for(int j=i+1;j<points.size();j++){
                int weight=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                graph[i].push_back({weight,j});
                graph[j].push_back({weight,i});
            }
        }
        vector<int>visited(vertices,0);
        vector<int> parent(vertices,-1);
        vector<int> minval(vertices,INT_MAX);
        minval[0]=0;
        visited[0]=1;
        for(int i=0;i<vertices-1;i++){
            int curr=findMin(minval,visited);
            visited[curr]=1;
            for(auto nbr : graph[curr]){
                if(!visited[nbr.second] && minval[nbr.second]>nbr.first){
                    minval[nbr.second]=nbr.first;
                    parent[nbr.second]=curr;
                }
            }
        }
        
        return findSum(minval);
    }
    int findMin(vector<int>& minval ,vector<int>& visited){
        int min=INT_MAX;
        int vertex=0;
        for(int i=0;i<minval.size();i++){
           if(min>minval[i] && !visited[i]){
               min=minval[i];
               vertex=i;
           }
        }
        return vertex;
    }
    
    int findSum( vector<int> minval){
        int sum=0;
        for(int i=0;i<minval.size();i++){
            sum+=minval[i];
        }
        return sum;
    }
};
