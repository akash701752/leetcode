class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        int res = 0;
        vroot = vector(2, vector(n,0));
        for(int t : {0,1}) for(int j=0;j<n;j++) vroot[t][j] = j;
        
        auto vedge = vector(3, vector<pair<int,int>>());
        for(auto& e:edges) vedge[e[0]-1].emplace_back(e[1]-1, e[2]-1);

        for(auto [i, j] : vedge[2]){
            bool f1 = connect(i, j, 0), f2 = connect(i, j, 1);
            if(!f1 && !f2) res++;
        }
        
        for(int type : {0,1})
            for(auto [i, j] : vedge[type])
                if(!connect(i, j, type)) res++;
        
        if(allConnected(0) && allConnected(1)) return res;
        return -1;
    }
    
    int root(int i, int type){
        auto& v = vroot[type];
        if(v[i] != i) v[i] = root(v[i], type);
        return v[i];
    }
    
    bool connect(int i, int j, int type){
        auto r1 = root(i, type), r2 = root(j, type);
        if(r1 == r2) return false;
        vroot[type][r1] = r2;
        return true;
    }

    bool allConnected(int type){
        const auto r = root(0, type);
        for(int i=0;i<vroot[type].size();i++)
            if(root(i, type) != r) return false;
        return true;
    }
    
    vector<vector<int>> vroot;
};
