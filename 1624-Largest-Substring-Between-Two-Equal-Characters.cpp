class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int max_len=-1;
        int i=0,len=s.size()-1;
        for(int i=0;i<len;i++){
            for(int j=len;j>0;j--){
                if(s[i]==s[j]){
                    max_len=max(max_len,j-i-1);
                    break;
                }
            }
        }
        return max_len;
    }
};
