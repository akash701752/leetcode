class Solution {
public:
    int maxVowels(string s, int k) {
        int vowel = 0 , i = 0 , j = 0 , mx = INT_MIN ;
        int n = s.length() ;
        while(j<n)
        {
            if(s[j]== 'a' || s[j]=='e' || s[j]=='i' || s[j]=='o' || s[j]=='u'){
                vowel++ ;
            }
            if((j-i+1)==k){
                mx = max(mx,vowel) ;
                if(s[i]== 'a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
                    vowel-- ;
                }
                i++;
            }
            j++;
        }
        return mx ;
    }
};
