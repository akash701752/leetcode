class Solution {
public:
    string reverseWords(string s) {
        istringstream ss(s) ;
        string w ;
        string ans = "" ;
        while(ss>>w){
            int size = w.size() , i = 0 ,j;
            j = size-1 ;
            while(i<j){
                swap(w[i],w[j]) ;
                i++ ;
                j-- ;
            }
            ans += w;
            ans.push_back(' ');
        }
        ans.pop_back() ;
        return ans ;
    }
};
