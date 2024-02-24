class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        map<int, vector<pair<int, int>>> mtgDict;
        
        sort(meetings.begin(), meetings.end(), sortByStartTime);
        
        for(const vector<int>& m : meetings){
            int time = m[2];
            mtgDict[time].push_back(pair(m[0], m[1]));
        }
        
        unordered_set<int> hasSecret;
        
        hasSecret.insert(0);
        hasSecret.insert(firstPerson);
        
        for(auto time = mtgDict.begin(); time != mtgDict.end(); time++){
            cout << time->first << endl;
            vector<pair<int, int>> meetingsOccuring = time->second;
            
            unordered_map<int, vector<int>> graph;
            unordered_set<int> seen;
            
            for(pair<int, int>& m : meetingsOccuring){
                int person1 = m.first;
                int person2 = m.second;
                
                graph[person1].push_back(person2);
                graph[person2].push_back(person1);
                
                if(hasSecret.find(person1) != hasSecret.end()) seen.insert(person1);
                if(hasSecret.find(person2) != hasSecret.end()) seen.insert(person2);
            }
            
            queue<int> q;
            
            for(auto s = seen.begin(); s != seen.end(); s++){
                q.push(*s);
            }
            
            while(!q.empty()){
                int person = q.front();
                q.pop();
                
                vector<int> neighbors = graph[person];
                
                
                for(int& n : neighbors){
                    if(hasSecret.find(n) == hasSecret.end()){
                        hasSecret.insert(n);
                        q.push(n);
                    }
                }
            }
        }
        vector<int> ans;
        
        for(auto person = hasSecret.begin(); person != hasSecret.end(); person++){
            ans.push_back(*person);
        }
        
        return ans;
    }
    
    static bool sortByStartTime(const vector<int>& v1, const vector<int>& v2){
        return v1[2] < v2[2];
    }
};
