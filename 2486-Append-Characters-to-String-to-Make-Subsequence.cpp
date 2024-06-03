class Solution {
public:
    int appendCharacters(string s, string t) {
        stack<char> st;
        int i = 0;
        for(auto it : s){
            if(it == t[i]){
                st.push(it);
                i++;
            }
            
        }
        
        return t.size() - st.size();
    }
};
