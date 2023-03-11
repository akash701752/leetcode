class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans ;
        unordered_map<string,int> mp ;
        for(auto str : words)
        {
            for(auto temp : words)
            {
                if(str!=temp)
                {
                    if(str.find(temp)!= string::npos){
                        if(mp.find(temp)==mp.end()){
                            ans.push_back(temp) ;
                            mp[temp]++ ;
                        }
                    }
                }
            }
        }
        return ans ;
    }
};
