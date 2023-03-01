class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int ind , n = items.size() , i , count = 0 ;
        if(ruleKey=="type"){
            ind = 0 ;
        }
        else if(ruleKey=="color"){
            ind = 1 ;
        }
        else{
            ind = 2 ;
        }
        for(i=0;i<n;i++){
            if(items[i][ind]==ruleValue){
                count++ ;
            }
        }
        return count ;
    }
};
