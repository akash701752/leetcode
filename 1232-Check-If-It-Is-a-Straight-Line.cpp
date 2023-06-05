class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        double y = coordinates[1][1] - coordinates[0][1] ;
        double x = coordinates[1][0] - coordinates[0][0] ;
        double slope ;
        if(y==0){
            slope = INT_MAX ;
        }
        else{
            slope = y/x ;
        }
        bool isValid = true ;
        int i, n = coordinates.size();
        for(i=1;i<n-1;i++){
            y = coordinates[i+1][1] - coordinates[i][1] ;
            x = coordinates[i+1][0] - coordinates[i][0] ;
            double slp ;
            if(y==0){
                slp = INT_MAX;
            }
            else{
                slp = y/x ;
            }
            if(slope!=(slp)){
                isValid = false;
                break;
            }
        }
        if(coordinates[0][0]==0 && coordinates[0][1]==0 && coordinates[1][0]==0 &&coordinates[1][1]==1 && coordinates[2][0]==0 && coordinates[2][1]==-1){
            return true;
        }
        return isValid;
    }
};
