class Solution {
public:
    string digitSum(string s, int k) {
        string str = s ;
        while(str.size()>k)
        {
            string temp = "" ;
            for(int i=0;i<str.length();i+=k){
                string t = str.substr(i,k) ;
                int c = 0 ;
                for(auto ch : t){
                    string tt = ""  ;
                    tt += ch ;
                    c += stoi(tt) ;
                }
                temp += to_string(c);
            }
            str = temp ;
        }
        return str ;
    }
};
