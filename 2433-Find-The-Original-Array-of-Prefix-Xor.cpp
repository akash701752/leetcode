class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size();
        vector<int> orig(n);
        int orig_prefix = pref[0];
        
        orig[0] = pref[0];
        
        for(int i = 1; i < n; i++) {
            orig[i] = orig_prefix ^ pref[i];
            orig_prefix ^= orig[i];
        }
        return orig;
    }
};
