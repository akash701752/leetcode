// Kahn's algorithm
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        list<int> *adj_list = new list<int>[numCourses];
        vector<int> indegree (numCourses, 0);
        queue<int> myqueue;
        int count{0};
        
        for (int i=0; i<prerequisites.size(); i++){
            vector<int> vec = prerequisites[i];
            adj_list[vec[1]].push_back(vec[0]);
            indegree[vec[0]]++;            
        }
        
        for(int i=0; i < numCourses; ++i){
            if (indegree[i] == 0)
                myqueue.push(i);
        }
        
        if (myqueue.empty())
            return false;
        
        while(!myqueue.empty()){
            count++;
            int v = myqueue.front();
            myqueue.pop();
            
            for (auto it=adj_list[v].begin(); it != adj_list[v].end(); ++it){
                indegree[*it]--;
                if (indegree[*it] == 0){
                    myqueue.push(*it);
                }
            }
        }
        
        if (count == numCourses){
            return true;
        }
        else{
            return false;
        }
        
    }
};
