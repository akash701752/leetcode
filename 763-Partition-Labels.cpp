class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> mp ;
        int i , n = s.length() ;
        for(i=0;i<n;i++){
            mp[s[i]] = i;
        }
        int prev = -1 , mx = 0 ;
        vector<int> ans ;
        for(i=0;i<n;i++)
        {
            mx = max(mx,mp[s[i]]);
            if(mx==i){
                ans.push_back(mx-prev);
                prev = mx ;
            }
        }
        return ans ;
    }
};
