class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int l1 = s1.size() , l2 = s2.size() , i ;
        if(l1>l2){
            return false ;
        }
        sort(s1.begin(),s1.end()) ;
        for(i=0;i<l2-l1+1;i++)
        {
            string str = s2.substr(i,l1) ;
            sort(str.begin(),str.end()) ;
            if(str==s1){
                return true ;
            }
        }
        return false ;
    }
};
