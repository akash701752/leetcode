class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        int mx= 0 ;
        string ans = "" ;
        
        string w;
        unordered_map<string,int> mp , ban ;
        for(auto s: banned){
            ban[s]++;
        }
        for(int i=0;i<paragraph.size();i++){
            //cout<<"Para[i] "<< paragraph[i] <<" ";
            if(paragraph[i]==','){
                paragraph[i] = ' ';
                //i++ ;
            } 
           //cout<<"Para[i] "<< paragraph[i] <<endl;  
        }
        istringstream ss(paragraph) ;
        //cout<<paragraph<<" ";
        string t ="" ;
        //stringstream ss(paragraph) ;
        while(ss>>w){
            string str = w ;
            int n= str.length() ;
            cout<<"Str = "<<str <<" ";
            if(n>0 && !isalpha(str[n-1])){
                //if(str[n-2])
                str.pop_back() ;
            }
            transform(str.begin(),str.end(),str.begin(),::tolower)  ;
            cout<<"str after : "<<str <<endl;
            // bool flag = true ;
            // for(auto s : banned){
            //     if(str==s){
            //         flag = false ;
            //         break ;
            //     }
            // }
            if(ban.find(str)==ban.end()){
                mp[str]++ ;
                if(mp[str]>mx){
                    mx = mp[str] ;
                    ans = str ;
                }
            }
            
        }
        return ans ;
    }
};
