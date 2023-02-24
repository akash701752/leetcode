class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> mp ;
        for(auto it : arr){
            mp[it]++ ;
        }
        priority_queue<int> pq ;
        for(auto it : mp){
            pq.push(it.second);
        }
        int n = arr.size() , newSize = n , count = 0 ;
        while(newSize>n/2)
        {
            newSize -= pq.top() ;
            pq.pop() ;
            count++ ;
        }
        return count ;
    }
};
