class Solution {
public:
    bool checkValidString(string s) {
        int i=0;
        stack<int> st1,st2;
        while(i<s.length())
        {
            switch(s[i])
            {
                case '(':st1.push(i);
                    break;
                case '*':st2.push(i);
                    break;
                case ')':if(!st1.empty())
                        st1.pop();
                    else if(!st2.empty())
                        st2.pop();
                    else
                        return false;
            }
            i++;
        }
        while(!st1.empty()&&!st2.empty())
        {
            if(st1.top()>st2.top())
                return false;
            st1.pop();
            st2.pop();
        }
        return st1.empty();
    }
};
