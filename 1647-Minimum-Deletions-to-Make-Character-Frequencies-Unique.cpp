class Solution {
public:
    int minDeletions(string s) {
        int n = s.length() ;
        vector<int> frq(26,0) ;
        for(int i=0;i<n;i++){
            int ind = s[i] - 'a' ;
            frq[ind]++;
        }
        int count = 0 ;
        sort(frq.begin(),frq.end());
        for(int i=0;i<25;i++){
            if(frq[i]==frq[i+1]&& frq[i]!=0){
                count++;
                frq[i]--;
                i=0;
            }
        }
        return count ;
    }
};
