class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int lines = 0 , width = 0 ;
        for(auto ch: s){
            width += widths[ch-'a'] ;
            if(width>100){
                lines++ ;
                width = 0 ;
                width += widths[ch-'a'] ;
            }
        }
        return {lines+1,width} ;
    }
};
