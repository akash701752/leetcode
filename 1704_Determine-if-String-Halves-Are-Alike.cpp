class Solution {
public:
    bool halvesAreAlike(string s) {
        int size = s.length() ;
        //int half = size/2 ;
        int count1 , count2 , i;
        count1=count2 = 0 ;
        for(i=0;i<size/2;i++){
            if( s[i]=='a' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='e' || s[i]=='A' || s[i]=='I' || s[i]=='O' || s[i]=='U'  || s[i]=='E' ){
                count1++ ;
            }
        }
        for(i=size/2;i<size;i++){
            if(s[i]=='a' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='e' || s[i]=='A' || s[i]=='I' || s[i]=='O' || s[i]=='U' || s[i]=='E'){
                count2++ ;
            }
        }
        if(count1==count2){
            return true ;
        }
        return false ;      
    }
};
