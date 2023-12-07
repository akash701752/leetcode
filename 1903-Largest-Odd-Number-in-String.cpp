// class Solution {
// public:
//     string largestOddNumber(string num) {
//         string ans ="" ;
//         int mx = -1 ;
//         int i , n = num.size() ;
//         int nn = stoi(num) ;
//         if(nn%2!=0){
//             return num ;
//         }
//         for(i=0;i<n;i++){
//             int n = stoi(num.substr(i,1));
//             if(n%2!=0){
//                 mx = max(mx,n) ;
//             }
//         }
//         if(mx!=-1){
//             ans+= to_string(mx) ;

//         }
//         return ans ;
//     }
// };
class Solution {
public:
    string largestOddNumber(string num) 
    {
        int n=num.size();
        if((num[n-1]-'0')%2==1)
        {
            return num;
        }
        while(num.size()!=0&&(num.back()-'0')%2==0)
        {
            num.pop_back();
        }
        return num;
    }
};
