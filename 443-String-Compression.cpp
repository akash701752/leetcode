class Solution {
public:
    int compress(vector<char>& chars) {
        string ans = "" ;
        int i , j , n = chars.size() , count ;
        if(n==1){
            return 1;
        }
        if(n==2){
            if(chars[0]==chars[1]){
                ans +=chars[0];
                ans+=to_string(2) ;
            }
            else{
                ans+=chars[0] ;
                ans+=chars[1] ;
            }
        }
        i = 0 , j =0 , count = 0 ;
        while(j<n && n>2)
        {
            count =0 ;
            char ch = chars[i] ;
            while(j<n &&chars[j]==ch ){
                count++ ;
                j++;
            }
            if(count==1){
                ans += ch ;
            }
            else{
                ans += ch ;
                ans += to_string(count) ;
            }
            i = j ;
        }
        chars.clear() ;
        for(auto s : ans){
            chars.push_back(s);
        }
        return ans.length();
    }
    
};
