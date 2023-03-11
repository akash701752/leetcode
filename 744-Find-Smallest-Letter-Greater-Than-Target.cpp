class Solution {
public:
    char getNext(vector<char>& letters, char target){
        int l , r , n = letters.size() ;
        char res = '#' ;
        l = 0 , r = n-1 ;
        while(l<=r){
            int mid = l+ (r-l)/2 ;
            if(letters[mid]==target){
                l = mid+1 ;
            }
            else if(letters[mid]<target){
                l = mid+1 ;
            }
            else if(letters[mid]>target){
                res = letters[mid] ;
                r = mid-1 ;
            }
        }
        return res;
    }
    char nextGreatestLetter(vector<char>& letters, char target) {
        char ans = getNext(letters,target) ;
        if(ans=='#'){
            return letters[0] ;
        }
        return ans;
    }
};
