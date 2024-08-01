class Solution {
public:
    int countSeniors(vector<string>& details) {
        int n = details.size();  
        int count = 0;           

        for(int i = 0; i < n; i++) {
            char c1 = details[i][11];
            char c2 = details[i][12];

            string ans;
            ans += c1;
            ans += c2;
            int age = stoi(ans);
            if(age > 60){
                count++;
            }
        }
        
        return count;
    }
};
