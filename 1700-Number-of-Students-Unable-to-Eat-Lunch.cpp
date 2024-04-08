class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int cnt = 0;
        while(cnt<students.size() && students.size()>0){
            if(students[0]==sandwiches[0]){
                students.erase(students.begin());
                sandwiches.erase(sandwiches.begin());
                cnt=0;
            }
            else{
                int x = students[0];
                students.erase(students.begin());
                students.push_back(x);
                cnt++;
            }
        }
        return cnt;
    }
};
