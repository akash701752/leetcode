class Solution {
public:
    int minOperations(vector<int>& nums) {
        int res=0;
        unordered_map<int,int> freq;
        for(auto &i : nums) {
            freq[i]++;
        }
        
        for(auto &i : freq) {
            if(i.second==1) return -1;
            int mod3=i.second%3;
            if(mod3==0) res+=(i.second/3);
            else if(mod3==1) res+=(((i.second-4)/3)+2);
            else res+=(i.second/3+1);
        }
        
        return res;
    }
};
