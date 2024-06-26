class Solution {
public:
    string largestGoodInteger(string num) {
        int count = 0;
        char prev = 'f';
        char ch = ' ';
        for(auto &it : num){
            if(it == prev) count++;
            else prev = it, count = 1;
            
            if(count == 3){
                if(ch < it) ch = it;
            }
        }
        if(ch == ' ') return "";
        string str;
        str.push_back(ch);
        str.push_back(ch);
        str.push_back(ch);
        return str;
    }
};
