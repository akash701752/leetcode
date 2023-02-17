class Solution {
public:
    int firstUniqChar(string s) {
        //Using Map
        unordered_map <char,int> mp;
        int i , n = s.length() ;
        for(i=0;i<n;i++){
            mp[s[i]]++ ;
        }
        for(i=0;i<n;i++){
            if(mp[s[i]]==1){
                return i ;
            }
        }
        return -1 ;
    }
};
