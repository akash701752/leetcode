class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size() ;
        sort(tokens.begin(),tokens.end()) ;

        if(n==0 || tokens[0]>power){
            return 0 ;
        }
        int j = n-1 , score = 0 ;

        for(int i=0;i<=j;i++){
            power -= tokens[i] ;

            if(power>=0){
                score++ ;
            }
            else{
                power += tokens[j] ;
                j--;
            }
        }
        return score; 
    }
};
