class Solution {
public:
    bool areNumbersAscending(string s) {
        istringstream ss(s) ;
        string w ;
        int prev = -1 ;
        while(ss>>w){
            if(w.length()>=1 && isdigit(w[0])){
                if(stoi(w)<=prev){
                    return false ;
                }
                else{
                    prev = stoi(w) ;
                    cout<<prev <<" ";
                }
            }
        }
        return true ;
    }
};
