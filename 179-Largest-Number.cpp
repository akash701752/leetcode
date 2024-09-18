class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> vec;
        for(int num : nums) {
            vec.push_back(to_string(num));
        }
        sort(vec.begin(), vec.end(), [](const string &a, const string &b) {
            return a + b > b + a;
        });
        if(vec[0] == "0") return "0";
        string s;
        for(const string &x : vec) {
            s += x;
        }
        return s;
    }
};
