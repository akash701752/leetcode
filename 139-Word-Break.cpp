class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> record = {0};
        for (int i=1; i<=s.size(); i++) {
            for (int j=record.size()-1; j>=0; j--) {
                string temp = s.substr(record[j], i-record[j]);
                if (find(wordDict.begin(), wordDict.end(), temp) != wordDict.end()) { record.push_back(i); break; }
            }
        }
        return record.back() == s.size() ? true : false;
    }
};
