class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) 
    {
        priority_queue <pair<int,int>> maxh ; // Max Hep
        int i , n = arr.size();
        for(i=0;i<n;i++)
        {
            maxh.push({abs(arr[i]-x),arr[i]}) ;
            if(maxh.size()>k)
            {
                maxh.pop() ;
            }
        }
        vector <int> res ;
        while(maxh.size()>0)
        {
            res.push_back(maxh.top().second) ;
            maxh.pop() ;
        }
        sort(res.begin(),res.end()) ;
        return res ;
    }
};
