class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int res = 0;
    
        for(size_t i = 0; i < points.size()-1; i++){
            res += std::max(std::abs(points[i+1][0] - points[i][0]),
                std::abs(points[i+1][1] - points[i][1]));
            
        }
        return res;
    }
};
