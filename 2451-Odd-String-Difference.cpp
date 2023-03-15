class Solution {
public:
    string oddString(vector<string>& words) {
        int i , j , n = words.size() , len = words[0].length();
        //sort(words.begin(),words.end()) ;
        //set<vector<int>> s ;
        map<vector<int>,vector<string>> s;
        //map<vector<int>> s ;
        string ans = "" ;
        for(i=0;i<n;i++)
        {
            vector<int> v ;
            for(j=1;j<len;j++){
                int n = (words[i][j] - 'a') - (words[i][j-1] - 'a' ) ;
                v.push_back(n) ;
            }
            for(auto n: v){
                cout<<n <<" ";
            }
            s[v].push_back(words[i]) ;
            // if(i==0){
            //     s.insert(v) ;
            // }
            // else{
            //     if(s.find(v)!=s.end()){
            //         s.insert(v) ;    
            //     }
            //     else{
            //         ans += words[i] ;
            //         break;   
            //     }
            // }
        }
        for(auto &it : s){
            if(it.second.size()==1){
                ans = it.second[0] ;
                break;
            }
        }
        return ans ;
    }
};
