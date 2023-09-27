class Solution {
public:
    string decodeAtIndex(string S, int K) {
        // string ans = "" ;
        // int i = 0 , j = 0 ;
        // int n = s.length() ;
        // string temp = "";
        // for(int i=0;i<n;i++){
        //     if(isdigit(s[i])){
        //         int digit = 0 ;
        //         int k = i ;
        //         while(k<n && isdigit(s[k])){
        //             digit += (s[k] - 0 *10) + s[k] - '0' ;
        //             k++;
        //         }
        //         i = k ;
        //         //int d = s[i] - '0' -1;
        //         int d = digit ;
        //         ans+= temp ;
        //         string newStr = ans;
        //         newStr ;
        //         while(d--){
        //             ans += newStr;
        //         }
        //         temp.clear();
        //     }
        //     else{
        //         temp.push_back(s[i]);
        //     }
        //     if(ans.size()>k){
        //         break;
        //     }
        // }
        // cout<<"String = "<<ans <<endl; 
        // string ch = "" ;
        // ch += ans[k-1];
        // if(ans.empty()){
        //     ch = "" ;
        //     ch += s[k-1];
        // }
        // return  ch ;
        
        
        long N = 0, i;
        for (i = 0; N < K; ++i)
            N = isdigit(S[i]) ? N * (S[i] - '0') : N + 1;
        while (i--)
            if (isdigit(S[i]))
                N /= S[i] - '0', K %= N;
            else if (K % N-- == 0)
                return string(1, S[i]);
        return "lee215";
    }
};
