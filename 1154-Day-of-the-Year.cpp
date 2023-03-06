class Solution {
public:
    bool isLeapYear(int year){
        if(year%400==0){
            return true ;
        }
        else if(year%100==0){
            return false ;
        }
        else if(year%4==0){
            return true ;
        }
        else{
            return false ;
        }
    }
    int dayOfYear(string date) {
        int day = stoi(date.substr(8,2)) ;
        int month = stoi(date.substr(5,2)) ;
        int year = stoi(date.substr(0,4)) ;
        int ans = 0 ;
        switch(month){
            case 1 :
                ans = day ;
                break;
            case 2 :
                ans = 31 + day ;
                break;
            case 3 :
                ans = 59 + day ;
                break;
            case 4 :
                ans = 90 +day ;
                break;
            case 5 :
                ans = 120 +day ;
                break;
            case 6 :
                ans = 151 +day ;
                break;
            case 7 :
                ans = 181 +day ;
                break;
            case 8 :
                ans = 212 +day ;
                break;
            case 9 :
                ans = 243 +day ;
                break;
            case 10 :
                ans = 273 +day ;
                break;
            case 11 :
                ans = 304 +day ;
                break;
            case 12 :
                ans = 334 +day ;
                break;
        }
        if(isLeapYear(year) && month>2){
            ans ++ ;
        }
        return ans ;
    }
};
