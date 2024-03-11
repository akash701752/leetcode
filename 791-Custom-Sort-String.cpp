// class Solution {
// public:
//     string customSortString(string order, string s) {
        
//     }
// };
class Solution {
public:
    string customSortString(string S, string T) {
        int pos[26]={0};
        for(int i=0;i<S.size();i++){
            pos[S[i]-'a']=i;
        }
        sort(T.begin(),T.end(),[pos](auto&a,auto&b){
           return pos[a-'a']<pos[b-'a']; 
        });
        return T;
    }
};
