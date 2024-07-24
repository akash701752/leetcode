class Solution {
public:
    bool static comp(pair<int,int>&a, pair<int,int>&b){
        return a.first<b.first;
    }
    vector<int> sortJumbled(vector<int>& map, vector<int>& nums) {
        vector<int> ans;
        vector<pair<int,int>>res;
        for(int i=0; i<nums.size(); i++){
            string s= to_string(nums[i]),y="";
            for(auto j : s){
                int ch= map[j-'0'];
                y+= to_string(ch);
            }
            int cur= stoi(y);
           res.push_back({cur,nums[i]});
        }
        sort(res.begin(),res.end(),comp);
        for(auto i : res) ans.push_back(i.second);
        return ans;
    }
};
