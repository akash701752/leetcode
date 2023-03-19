class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        int n1 = items1.size()  , n2 = items2.size() , i , j ;
        map<int,int> mp ;
        for(i=0;i<n1;i++){
            mp[items1[i][0]] = items1[i][1] ;
        }
        for(i=0;i<n2;i++){
            mp[items2[i][0]] += items2[i][1] ;
        }
        vector<vector<int> > ans ;
        // sort(items1.begin(),items1.end()) ;
        // sort(items2.begin(),items2.end()) ;
        // i = 0 , j = 0 ;
        // 
        // while(i<n1 && j<n2)
        // {
        //     if(items1[i][0]==items2[j][0]){
        //         ans.push_back({items1[i][0],items1[i][1]+items2[j][1]}) ;
        //         i++ ;
        //         j++ ;
        //     }
        //     else if(items1[i][0]<items2[j][0]){
        //         i++;
        //     }
        //     else{
        //         j++;
        //     }
        // }
        // while(i<n1)
        // {
        //     ans.push_back({items1[i][0],items1[i][1]}) ;
        //     i++ ;
        // }
        // while(j<n2)
        // {
        //     ans.push_back({items2[i][0],items2[i][1]}) ;
        //     j++ ;
        // }
        for(auto n : mp){
            ans.push_back({n.first,n.second}) ;
        }
        return ans ;
    }
};
