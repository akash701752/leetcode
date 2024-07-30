class Solution {
public:
    int minimumDeletions(string s) {
        bool flag=false;
        int cnt=0, cntb=0,cnta=0;
        stack<char>st;
        for(char ch:s){
           if(ch=='a' && !st.empty() && st.top()=='b')
           st.pop();
           else
           st.push(ch);
        }
        
        return (s.size()-st.size())/2;
    }
};
