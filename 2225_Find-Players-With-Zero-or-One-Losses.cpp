class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) 
    {
        //Using Map
        unordered_map <int,int> mp ;
        int i , n = matches.size() ;
        for(i=0;i<n;i++)
        {
            mp[matches[i][1]] ++ ;
        }
        vector <int> loser, winner ;
        for(i=0;i<n;i++)
        {
            if(mp[matches[i][1]]==1){
                loser.push_back(matches[i][1]) ;
            }
            if(mp.find(matches[i][0])==mp.end())
            {
                winner.push_back(matches[i][0]) ;
                mp[matches[i][0]] = 2 ; // flag for no duplicates
            }
        }
        sort(winner.begin(),winner.end()) ;
        sort(loser.begin(),loser.end()) ;
        vector<vector<int>> res ;
        res.push_back(winner) ;
        res.push_back(loser) ;
        return res; 
    }
};
