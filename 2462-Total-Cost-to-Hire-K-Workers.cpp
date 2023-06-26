class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int, vector<int>, greater<int>> back;
        priority_queue<int, vector<int>, greater<int>> front;
        long long ans = 0;
        int left = 0, right = costs.size()-1;
        for(int i = 0; i < candidates; i++){
            if(left < costs.size()) back.push(costs[left]);
            left++;
            if(left >= costs.size()) break;
        }
        left--;
        for(int i = 0; i < candidates; i++){
            if(left >= right) break;
            front.push(costs[right]);
            right--;
            if(right < 0) break;
        }
        right++;
        while(k){
            if(back.empty()){
                ans += (front.top());
                front.pop();
                right--;
                if(right > left && right >= 0) front.push(costs[right]);
            }
            else if(front.empty() || back.top() <= front.top()){
                ans += back.top();
                back.pop();
                left++;
                // cout << left << " " << "LEFT" << endl;
                if(left<costs.size() && left < right) back.push(costs[left]);
            }
            else{
                ans += front.top();
                front.pop();
                right--;
                if(right > left && right >= 0) front.push(costs[right]);
                
            }
            k--;
        }
        return ans;
        
    }
};
