class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int sum = 0;
        int n = grumpy.size();
        int ans = 0;
        int i;
        
        for(int i = 0; i < grumpy.size(); i++) {
            sum += grumpy[i] == 0 ? customers[i] : 0;
        }

        for(i = 0; i < minutes; i++) {
            sum += grumpy[i] == 1 ? customers[i] : 0;
        }

        ans = max(ans, sum);
    
        while(i < n) {
            if(grumpy[i - minutes] == 1)
                sum -= customers[i - minutes];
            if(grumpy[i] == 1)
                sum += customers[i];
            ans = max(ans, sum);
            i++;
        }

        return ans;
    }
};
