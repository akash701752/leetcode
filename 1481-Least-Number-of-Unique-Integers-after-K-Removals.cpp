class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> mp ;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        int n= arr.size() ;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }

        for(auto it: mp){
            pq.push({it.second,it.first});
        }

        while(k>0){
            pair<int,int> del = pq.top() ;
            if(k>=del.first){
                k -= del.first ;
                pq.pop();
            }
            else{
                break;
            }  
        }
        return pq.size();
    }
};
