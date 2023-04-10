class Solution {
public:
    bool isValid(string s) {
        stack<char> st ;
        int i , n = s.length() ;
        for(i=0;i<n;i++)
        {
            if(s[i]=='('){
                st.push(')') ;
            }
            else if(s[i]=='['){
                st.push(']') ;
            }
            else if(s[i]=='{'){
                st.push('}') ;
            }
            else{
                if(st.empty() || s[i]!=st.top()){
                    return false ;
                }
                st.pop();
            }
        }
        return st.empty() ;
    }
};
