class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans ;
        int i , n = s.length() ;
        for(i=0;i<n;i+=k)
        {
            string str = s.substr(i,k) ;
            string temp = "" ;
            if(str.length()==k){
                temp += str ;
            }
            else{
                for(auto ch: str){
                    temp+= ch ;
                }
                while(temp.length()!=k){
                    temp += fill ;
                }
            }
            ans.push_back(temp) ;
        }
        return ans ; 
    }
};
