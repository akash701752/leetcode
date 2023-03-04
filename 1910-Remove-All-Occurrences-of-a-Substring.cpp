class Solution {
public:
    string removeOccurrences(string s, string part) {
        int i , n= s.size() , size = part.length();
        do{
            int ind = s.find(part) ;
            if(ind>-1){
                for(i=0;i<size;i++){
                    s.erase(s.begin()+ind) ;
                }
            }
        }while(s.find(part)!= string::npos);
        return s ;
    }
};
