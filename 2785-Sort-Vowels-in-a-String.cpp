class Solution {
public:
    string sortVowels(string s) {
        vector<char> vow = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        string ans;
        vector<char> store;
        for(char c: s){
            if(find(vow.begin(), vow.end(), c) != vow.end()){
                store.push_back(c);
            }
        }
        sort(store.begin(), store.end());

        int idx = 0;
        for(char c: s){
            if(find(vow.begin(), vow.end(), c) != vow.end()){
                ans += store[idx++];
            }
            else    ans += c;
        }
        return ans;
    }
};
