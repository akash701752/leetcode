class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int val=mean*(rolls.size()+n);
        int sum=accumulate(rolls.begin(),rolls.end(),0);
        int x=val-sum;
        if(x<0){
            return {};
        }
        vector<int>ans(n,0);
        int i=0;
        while(x){
            ans[i]++;
            i++;x--;
            if(i==n){
                i=0;
            }
        }
        if(ans[0]>6||ans[n-1]==0){
            return {};
        }
        return ans;
    }
};
