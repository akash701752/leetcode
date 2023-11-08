class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int dx = abs(sx-fx);
        int dy = abs(sy - fy);

        if(dx == 0 && dy == 0){
            return  t != 1;
        }
        
        int mintime = max(dx, dy);
        
        if(mintime <= t){
            return true;
        }

        return false;
    }
};
