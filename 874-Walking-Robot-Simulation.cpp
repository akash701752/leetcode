class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        vector<int> dir = {0, 1};
        int xp = 0, yp = 0, maxDist = 0;

        unordered_map<int, unordered_set<int>> map;

        for (const auto& ob : obstacles) {
            map[ob[0]].insert(ob[1]);
        }

        for (int c : commands) {
            int x = dir[0], y = dir[1];
            if (c == -2) {
                dir[0] = x != 0 ? 0 : (y == -1 ? 1 : -1);
                dir[1] = y != 0 ? 0 : (x == -1 ? -1 : 1);
            } else if (c == -1) {
                dir[0] = x != 0 ? 0 : (y == -1 ? -1 : 1);
                dir[1] = y != 0 ? 0 : (x == -1 ? 1 : -1);
            } else {
                while (c-- > 0) {
                    xp += x;
                    yp += y;
                    if (map[xp].find(yp) != map[xp].end()) {
                        xp -= x;
                        yp -= y;
                        break;
                    }
                }
                maxDist = max(maxDist, xp * xp + yp * yp);
            }
        }

        return maxDist;
    }
};
