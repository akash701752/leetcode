class Solution {
public:
    int partitionString(string s) {
        int count = 0 ;
        set<char> st ;
        for(auto ch:s){
            if(st.find(ch)!=st.end()){
                count++ ;
                st.clear() ;
            }
            st.insert(ch) ;
        }
        return count+ 1 ;
    }
};
