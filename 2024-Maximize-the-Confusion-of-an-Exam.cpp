class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        int j = 0 , ans = 0 , temp = k;
        for(int i=0; i<s.length(); )
        {
            if(s[i] == 'T')
                i++;
            else if(k > 0)
            {
                k--;
                i++;
            }
            else
            {
                if(s[j] == 'F')
                    k++;
                j++;
            }
            ans = max(ans , i - j);
        }
         j = 0 , k = temp;
        for(int i=0; i<s.length(); )
        {
            if(s[i] == 'F')
                i++;
            else if(k > 0)
            {
                k--;
                i++;
            }
            else
            {
                if(s[j] == 'T')
                    k++;
                j++;
            }
            ans = max(ans , i - j);
        }
        return ans;
    }
};
