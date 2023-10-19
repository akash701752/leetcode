class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> first;
        stack<char> second;
        for (auto item : s){
            if (!first.empty() && item == '#')
                first.pop();
            if (item != '#')
                first.push(item);
        }
        for (auto item : t){
            if (!second.empty() && item == '#')
                second.pop();
            if (item != '#')
                second.push(item);
        }
        
        return first == second;
    }
};
