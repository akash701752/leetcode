class Solution {
public:
    int numSteps(string s) {
        int n = s.size()-1, steps = 0 ;
        
        while(n>0 && s[n]=='0'){
            n--;steps++;
        }
        
        while(n){            
            if(n==0){
                break;
            }
            while(n>0 && s[n]=='1'){
                n--; steps++;
            }
            
            if(n==0){
                return steps + 2 ;
            }
            if(s[n]=='0'){
                s[n]='1' ; steps++;
            }
        }
        
        return steps;
    }
};
