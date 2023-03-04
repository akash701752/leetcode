class Solution {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        string a , b , c ;
        a = b = c = "" ;
        for(auto s : firstWord){
            int n = s - 'a' ;
            a += to_string(n);
        }
        cout<< "a = "<<a <<endl;
        for(auto s : secondWord){
            int n = s - 'a' ;
            b += to_string(n);
        }
        cout<< "b = " <<b<<endl;
        int b_c = stoi(a) + stoi(b) ;
        cout<< "b_c = " <<b_c<<endl;
        string firstSec = "" ;
        firstSec += to_string(b_c) ;
        
        for(auto s : targetWord){
            int n = s - 'a' ;
            c += to_string(n);
        }
        cout<<"c = "<<c <<endl ;
        if(b_c==0 && stoi(c)==0){
            return true;
        }
        // return firstSec.compare(c) ;
        return stoi(firstSec) == stoi(c) ;
    }
};
