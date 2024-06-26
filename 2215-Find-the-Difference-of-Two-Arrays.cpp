class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1, s2;
        for (auto& i : nums1)
            s1.insert(i);
        for (auto& j : nums2)
            s2.insert(j);  
        vector<vector<int>> ans(2);
        for (auto& i : s1)
            if (!s2.count(i))
                ans[0].push_back(i);
        for (auto& j : s2)
            if (!s1.count(j))
                ans[1].push_back(j);
        return ans;
    }
};
