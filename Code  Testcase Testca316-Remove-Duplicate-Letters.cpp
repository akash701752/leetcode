class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char> st ;
        unordered_map<char,int> mp ;
        vector<int> freq(26,0) ;
        int n= s.length();
        for(auto x:s){
            mp[x]++;
        }
        for(int i=0;i<n;i++){
            char ch = s[i] ;
            if(freq[ch-'a']){
                mp[ch]--;
                continue ;
            }
            while(!st.empty() && st.top()>ch && mp[st.top()]>=1){
                freq[st.top()-'a'] = 0;
                st.pop();
            }
            st.push(ch);
            mp[ch]-- ;
            freq[ch-'a'] = 1;
        }
        string ans ;
        while(st.size()>0){
            //ans += st.top();
            ans.push_back(st.top());
            st.pop() ;
        }
        //cout<<"ans = "<<ans;
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
