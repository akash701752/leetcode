class Solution {
public:

class Objects {
public:
    int position;
    int health;
    int order;
    int direction;

    Objects(int p, int h, int o, int d) : position(p), health(h), order(o), direction(d) {}
};

static bool compareByPosition(const Objects &a, const Objects &b) {
    return a.position < b.position;
}
static bool compareByOrder(const Objects &a, const Objects &b) {
    return a.order < b.order;
}

    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<Objects> obj;
        int n=positions.size();
        for(int i=0;i<n;i++){
            obj.push_back(Objects(positions[i], healths[i],i,directions[i]=='L'?1:2));
        }
        sort(obj.begin(), obj.end(), compareByPosition);
        stack<Objects> st;
        for(int i=0;i<n;i++){
            Objects ob = obj[i];

            while(!st.empty() && 
            ob.health >0 && 
            st.top().direction == 2 && ob.direction == 1){
                if(st.top().health==0) {
                    st.pop();
                    continue;
                }
                if(st.top().health==ob.health) {
                    st.pop();
                    ob.health=0;
                }
                else if(st.top().health > ob.health) {
                    st.top().health--;
                    ob.health=0;
                }
                else {
                    st.pop();
                    ob.health--;
                }
            }
            if(ob.health>0) st.push(ob);
        }
        obj.clear();
        while(!st.empty()){
            obj.push_back(st.top());
            st.pop();
        }
        sort(obj.begin(), obj.end(), compareByOrder);
        vector<int> ans;
        for(int i=0;i<obj.size();i++){
            ans.push_back(obj[i].health);
        }
        return ans;
    }
};
