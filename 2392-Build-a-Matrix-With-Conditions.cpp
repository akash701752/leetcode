class Solution {
public:
vector<int> topo_sort(int k, vector<vector<int>>& conditions) {
    vector<int> in_deg(k + 1, 0);
    unordered_map<int, vector<int>> g;
    
    for (auto& cond : conditions) {
        int u = cond[0], v = cond[1];
        g[u].push_back(v);
        in_deg[v]++;
    }
    
    queue<int> q;
    for (int i = 1; i <= k; ++i) {
        if (in_deg[i] == 0) {
            q.push(i);
        }
    }
    
    vector<int> topo_ord;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topo_ord.push_back(node);
        
        for (int neigh : g[node]) {
            if (--in_deg[neigh] == 0) {
                q.push(neigh);
            }
        }
    }
    
    if (topo_ord.size() == k) {
        return topo_ord;
    } else {
        return {};
    }
}

   vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
    vector<int> row_ord = topo_sort(k, rowConditions);
    vector<int> col_ord = topo_sort(k, colConditions);
    
    if (row_ord.empty() || col_ord.empty()) {
        return {};
    }
    
    unordered_map<int, int> row_pos, col_pos;
    for (int i = 0; i < k; ++i) {
        row_pos[row_ord[i]] = i;
        col_pos[col_ord[i]] = i;
    }
    
    vector<vector<int>> mat(k, vector<int>(k, 0));
    for (int num = 1; num <= k; ++num) {
        int r = row_pos[num];
        int c = col_pos[num];
        mat[r][c] = num;
    }
    
    return mat;
    }
};
