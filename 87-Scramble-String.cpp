class Solution {
public:
    unordered_map<string,bool> mp ;
    bool solve(string a, string b)
    {
        if(a.compare(b)==0){
        return true ;
        }
        if(a.length()<=1){
            return false ;
        }
        string key = a ;
        key.push_back(' ');
        key.append(b) ;
        
        if(mp.find(key)!=mp.end()){
            return mp[key] ;
        }
        int n = a.length() , i ;
        bool flag = false ;
        for(i=1;i<n;i++)
        {
            if( solve(a.substr(0,i),b.substr(n-i,i))==true && solve(a.substr(i,n-i),b.substr(0,n-i))==true ){
                flag = true ;
                break ;
            }
            if( solve(a.substr(0,i),b.substr(0,i))==true && solve(a.substr(i,n-i),b.substr(i,n-i))==true ) {
                flag = true ;
                break ;
            }
        }
        return mp[key]=flag ;
    }
    
    bool isScramble(string s1, string s2) {
        bool ans = solve(s1,s2) ;
        return ans ;
    } 
};
