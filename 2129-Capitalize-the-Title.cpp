class Solution {
public:
    string capitalizeTitle(string s) 
    {
        string ans = "" , w ;
        istringstream ss(s) ;
        while(ss>>w)
        {
            if(isupper(w[0]) && w.length()<3){
                w[0] = tolower(w[0]);
            }
            else if(islower(w[0]) && w.length()>2){
                w[0] = toupper(w[0]) ;
            }
            for(int i=1;i<w.length();i++){
                if(isupper(w[i])){
                    w[i] = tolower(w[i]);
                }
            }
            ans += w ;
            ans.push_back(' ');
        } 
        ans.pop_back() ;
        return ans ;
    }
};
