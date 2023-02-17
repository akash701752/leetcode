class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int l1 = s.length() ,i ;
        vector<int> v1(256,0) , v2(256,0) ;
        for(i=0;i<l1;i++)
        {
            if(v1[s[i]] != v2[t[i]]){
                return false;
            }
            v1[s[i]] = i+1;
            v2[t[i]] = i+1;
        }
        return true ;
    }
};
