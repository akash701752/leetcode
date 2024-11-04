class Solution {
public:
    string compressedString(string word) {
     string comp;
     int count=1;
     for(int i=0;i<word.length()-1;i++){
         if(word[i]==word[i+1]&&count<9){
            count++;
         }else{
            comp += to_string(count);
            comp += word[i];

            count =1;
         }
     }   
            comp += to_string(count);
            comp += word[word.length()-1];
 
        return comp;
    }
};
