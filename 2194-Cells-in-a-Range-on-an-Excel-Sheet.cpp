class Solution {
public:
    vector<string> cellsInRange(string s) {
        int colStart= s[1] - '0', colEnd =   s[4] - '0' ;
        int col = s[3] - s[0] +1;
        char ch1 = s[0] , ch2 = s[3] ;
        int row = (s[4] - '0') - (s[1] -'0') +1 ;
        vector<string> res ;
        cout<<"ColStart = "<<colStart <<endl ;
        cout<<"ColEnd = "<<colEnd <<endl ;
        cout<<"Column = "<<col<<endl ;
        for(int j=0;j<col;j++)
        {
            for(int i=colStart;i<=colEnd;i++)
            {
                string str = "";
                str += (ch1) ;
                str += to_string(i) ;
                res.push_back(str) ;
            }
            ch1++ ;
        }
       
        return res ;
    }
};
