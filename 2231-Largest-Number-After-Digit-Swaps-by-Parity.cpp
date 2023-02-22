class Solution {
public:
    int largestInteger(int num) {
        string str = to_string(num) ;
        int n= str.size() , i , j ;
        for(i=0;i<n;i++)
        {
            int ind = i , a = str[i] -'0' ; 
            for(j=i;j<n;j++)
            {
                int b= str[j]-'0' ;
                if((a%2==0 && b%2==0) && b>a){
                    a = b ;
                    ind = j ;
                }
                else if((a%2!=0 && b%2!=0) && b>a){
                    a = b ;
                    ind = j ;
                }
            }
            swap(str[i],str[ind]) ;
        }
        return stoi(str) ;
    }
};
