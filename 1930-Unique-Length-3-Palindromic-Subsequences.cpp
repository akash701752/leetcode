class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int arr[26][2];
        
        for(int i=0;i<26;i++){
            arr[i][0]=INT_MAX;
            arr[i][1]=INT_MIN;
        }
        
        for(int i=0;i<s.length();i++){
            int ch=s[i]-'a';
            if(arr[ch][0]==INT_MAX)
                arr[ch][0]=i;
            else
                arr[ch][1]=i;
        }
        int ans=0;
        for(int i=0;i<26;i++){
            if(arr[i][0]!=INT_MAX and arr[i][1]!=INT_MIN){
                int l=arr[i][0];
                int r=arr[i][1];
                
                set<char> st;
                l++;
                while(l<r)
                    st.insert(s[l++]);
                ans+=st.size();
            }
        }
        return ans;
    }
};
