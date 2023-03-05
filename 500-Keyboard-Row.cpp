class Solution {
public:

    vector<string> findWords(vector<string>& words) {
        unordered_map<char,int> mp ;
        string s1 = "qwertyuiop" ; 
        string s2 = "asdfghjkl" ; 
        string s3 = "zxcvbnm" ; 
        for(auto s : s1){   
            mp[s] = 1;
        }
        for(auto s : s2){
            mp[s] = 2;
        }
        for(auto s : s3){
            mp[s] = 3;
        }
        vector<string> ans ;
        for(auto s : words){
            string str = s ;
            transform(str.begin(),str.end(),str.begin(),::tolower) ;
            cout<<s ;
            int n = s.length() , c = 0 , i ;
            for(i=1;i<n;i++){
                if(mp[str[i-1]]!=mp[str[i]]){
                    break;
                }
                else{
                    c++;
                }
            }
            if(c==n-1){
                ans.push_back(s) ;
            }
        }
        return ans ;
    }
};
