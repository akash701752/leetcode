class Solution {
public:
    void reverse(string &word,int i,int j){
        while(i<j){
            swap(word[i],word[j]);
            i++;
            j--;
        }
    }
    string reversePrefix(string word, char ch) {
        int ind = 0 , i , n = word.length() ;
        for(i=0;i<n;i++){
            if(word[i]==ch){
                ind = i ;
                break ;
            }
        }
        reverse(word,0,ind);
        return word ;
    }
};
