class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char,char> mp ;
        int i , n = key.length() ;
        char ch = 'a' ;
        vector<char> v(26,'$') ;
        for(i=0;i<n;i++){
            if(key[i]>='a' && key[i]<='z' && v[key[i]-'a']=='$'){
                v[key[i]-'a'] = ch ++ ;
            }
        }
        string ans = message ;
        int size = message.length() ;
        for(i=0;i<size;i++){
            if(message[i]!=' '){
                ans[i] = v[message[i]-'a'] ;
            }
            else{
                ans[i] = message[i] ;
            }
        }
        return ans ;
    }
};
