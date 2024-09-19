class Solution {
public:
    vector<int> fun(string s, int i, int j){
        vector<int> res; 
        // if size is 1 then its only one int value return it
        if(j - i == 0) return {(int) s[i] - '0'};
        // if size is 3 then it conatins one operator and 2 integers
        if(j - i + 1 == 3){
            int x = s[i] - '0'; //to convert char to integer
            int y = s[j] - '0';
            if(s[i + 1] == '+') return {x + y};
            if(s[i + 1] == '-') return {x - y};
            if(s[i + 1] == '*') return {x * y};
        } 
        for(int k = i; k < j + 1; k++){
            //spliting the expression at operators
            if(s[k] == '*' or s[k] == '-' or s[k] == '+'){
                vector<int> v1 = fun(s, i, k - 1), v2 = fun(s, k + 1, j);         // combining the both expressions
                for(int x : v1){
                    for(int y : v2){
                        if(s[k] == '*') res.push_back(x * y);
                        if(s[k] == '+') res.push_back(x + y);
                        if(s[k] == '-') res.push_back(x - y);
                    }
                }
            }
        }
        // if substring only conatins the numeric values and no operators
        if(res.size() == 0) res = {stoi(s.substr(i, j + 1))} ;
        return res;
    }
    vector<int> diffWaysToCompute(string expression) {
       return fun(expression, 0, expression.size() - 1);
    }
};
