
class Solution {
	public:
    string minRemoveToMakeValid(string s) {
        //to store value and its index
			stack<pair<int, int>> st;
        string temp;
        for(int i = 0;i<s.size();i++)
        {
            //if we have to remove symbol, store some other symbol instead of this:
            if(s[i] == ')' && st.empty())
                s[i] = '{';
            else if(s[i] == ')' && !st.empty())
                st.pop();
            else if(s[i] == '(')
                st.push({s[i], i});
                
        }
         
        while(!st.empty())
        {
            s[st.top().second] = '{';
            st.pop();
        }
        //store required string into some temp,don't include symbols which we have to remove.
        for(int i = 0;i<s.size();i++)
        {
            if(s[i] != '{')
                temp.push_back(s[i]);
        }
        return temp;
    }
};
