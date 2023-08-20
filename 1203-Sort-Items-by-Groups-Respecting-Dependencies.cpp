class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        for(int i=0;i<n;i++){
            if(group[i]==-1){
                group[i] = m++;
            }
        }

        unordered_set<int> ig[n]; // item graph
        unordered_set<int> gg[m]; // group graph
        
        //creating two graphs one for items and one for 
        for(int i=0;i<n;i++){
            int grpa = group[i]; // group of child
            for(auto it:beforeItems[i]){
                int grpb = group[it]; // group of parent
                if(grpa!=grpb){
                    gg[grpb].insert(grpa);
                }
                ig[it].insert(i);
            }
        }
        
        vector<int> ordered_items = topo(ig,n);
        vector<int> ordered_groups = topo(gg,m);
        
        map<int,vector<int>> elems_of_grp;
        //storing items in their respective groups in toplogical order
        for(auto it:ordered_items){
            elems_of_grp[group[it]].push_back(it);
        }
        
        //iterating over the groups and adding the items stored in those groups in prev for loop to ans vector 
        vector<int> ans;
        for(auto it:ordered_groups){
           for(auto el:elems_of_grp[it]){
            ans.push_back(el);   
           }
        }
        return ans;
    }
    
  vector<int> topo(const unordered_set<int> g[],int n) {
    int k = n;
    int cnt = n;
    vector<int> indeg(k), ret;
    for(int i = 0; i < k; i ++)
        for(int v : g[i]) indeg[v] ++;
    queue<int> q;
    for(int i = 0; i < k; i ++)
        if(indeg[i] == 0) q.push(i);
    while(!q.empty()) {
        int i = q.front(); // top() for priority queue
        ret.push_back(i);
        cnt--;
        q.pop();
        for(int x : g[i])
            if(--indeg[x] == 0) q.push(x);
    }
    return cnt==0?ret:vector<int>{};
}
};
