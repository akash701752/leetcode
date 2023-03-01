class Solution {
public:
    string toLowerCase(string s) 
    {
        int i , n = s.size() ;
        for(i=0;i<n;i++){
            if(s[i]>='A' && s[i]<='Z'){
                s[i] = s[i] - 'A' + 'a';
            }
        }
        return s;
    }
};
