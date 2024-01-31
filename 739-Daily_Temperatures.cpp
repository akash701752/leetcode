class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int  i , n= temperatures.size();
        stack<int> st ;
        vector<int> ans(n) ;
        for(i=0;i<n;i++)
        {
            while(st.size()>0 && temperatures[st.top()]<temperatures[i])
            {
                ans[st.top()] = i - st.top() ;
                st.pop() ;
            }
            st.push(i) ;
        }
        return ans ;
    }
};
