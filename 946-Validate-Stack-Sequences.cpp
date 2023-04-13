class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st ;
        int i , ind= 0 , n = pushed.size();
        for(i=0;i<n;i++){
            st.push(pushed[i]);
            while(st.size()>0 && st.top()==popped[ind]){
                st.pop() ;
                ind++;
            }
        }
        return st.size()==0 ;
    }
};
