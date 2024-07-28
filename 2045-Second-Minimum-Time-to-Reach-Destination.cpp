class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> adj(n + 1);
        for (auto& it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> min_time(n + 1, INT_MAX);
        vector<int> second_min_time(n + 1, INT_MAX);

        queue<pair<int, int>> q;
        q.push({1, 0});
        min_time[1] = 0;

        while (!q.empty()) {
            auto [node, t] = q.front();
            q.pop();

            int ch = t / change;
            int wait_time = (ch % 2 == 1) ? (ch + 1) * change : t;
//see here if we are at a node and time is odd mmultiple of 
//change then we'll take the nearest even multiple of time
//or else simply add the wait_time
//That's it now simply do bfs traversal and for each node keep 
//comparing the time to min and second min and keep on updating
            int new_time = wait_time + time;

            for (int adjnode : adj[node]) {
                if (new_time < min_time[adjnode]) {
                    second_min_time[adjnode] = min_time[adjnode];
                    min_time[adjnode] = new_time;
                    q.push({adjnode, new_time});
                } else if (new_time > min_time[adjnode] && new_time < second_min_time[adjnode]) {
                    second_min_time[adjnode] = new_time;
                    q.push({adjnode, new_time});
                }
            }
        }

        return second_min_time[n];
    }
};
