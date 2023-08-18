class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& road) {
        vector<int> count(n,0);
        vector<vector<int>> direct(n,vector<int>(n,0)); //no of directly connected city for each city
        for(int i=0;i<road.size();i++) 
        {
            count[road[i][0]]++; //no of connections 
            count[road[i][1]]++; //the connection is bidirectional
            direct[road[i][0]][road[i][1]]=1;
            direct[road[i][1]][road[i][0]]=1;
        }
        int rank=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++) {
                rank = max(rank,count[i]+count[j]-direct[i][j]); 
/*it is not necessary that the 2 cities with most connections need to be connected with each other and if they are connected the common connection is counted only once*/
            }
        }
        return rank;
    }
};
