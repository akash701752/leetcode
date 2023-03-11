class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans = 0;
        for(auto ch : columnTitle)
        {
			int c = ch - 'A' + 1;
            ans = ans * 26 + c ;
        }
        return ans ;
    }
};
