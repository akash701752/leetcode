class Solution {
public:
    int integerBreak(int n) {
        if (n==2)
            return 1;
        if (n==3)
            return 2;
        if (n%3 == 0)
        {
            return pow(3,n/3);
        }
        if (n%3 == 2)
        {
            return pow(3,n/3)*2;
        }
        return pow(3,(n/3)-1)*4;
        
    }
};
/*
        2 - 1,1
        3 - 1,2
        4 - 2,2
        5 - 3,2
        6 - 3,3
        7 - 3,4
        8 - 3,3,2
        9 - 3,3,3
        10 - 3,3,4
        11 - 3,3,3,2
        12 - 3,3,3,3
        13 - 3,3,3,4
