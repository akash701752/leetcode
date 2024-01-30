class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> st ; 
        for(string x : tokens)
        {
            if(x=="+"){
                long long a = st.top() ;
                st.pop() ;
                long long b = st.top() ;
                st.pop() ;
                st.push(a+b) ;
            }
            else if(x=="*"){
                long long a = st.top() ;
                st.pop() ;
                long long b = st.top() ;
                st.pop() ;
                st.push(a*b) ;
            }
            else if(x=="-"){
                long long a = st.top() ;
                st.pop() ;
                long long b = st.top() ;
                st.pop() ;
                st.push(b-a) ;
            }
            else if(x=="/"){
                long long a = st.top() ;
                st.pop() ;
                long long b = st.top() ;
                st.pop() ;
                st.push(b/a) ;
            }
            else{
                st.push(stoi(x)) ;
            }
        }
        return (int) st.top() ;
    }
};
