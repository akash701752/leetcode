class Solution {
public:
    static bool comp(vector<int> a,vector<int> b)
    {
        // for sorting on the basis of frequency
        if(a[0]<b[0])
        {
            return true ;
        }
        if(a[0]==b[0])
        {
            return a[1]>b[1] ;
        }
        return false ;
    }
    vector<int> frequencySort(vector<int>& nums) 
    {
        //priority_queue <pair<int,int> , vector <pair<int,int>> , greater<pair<int,int>> > minh ;
        unordered_map <int,int> mp ;
        int i , n = nums.size() ;
        for(i=0;i<n;i++){
            mp[nums[i]]++ ;
        }
        /*
        for(auto it = mp.begin(); it!=mp.end() ; it++)
        {
            minh.push({it->second,it->first}) ;
        }
        vector <int> res ;
        while(minh.size()>0)
        {
            int fq = minh.top().first ;
            int ele = minh.top().second ;
            for(int j=0;j<fq;j++){
                res.push_back(ele) ;
            }
            minh.pop() ;
        }
        return res ;
        */
        vector <vector<int>> vec ;
        for(auto it = mp.begin(); it!=mp.end() ; it++) {
            vec.push_back({it->second,it->first}) ;
        }
        sort(vec.begin(),vec.end(),comp) ;
        vector <int> res ;
        //vector <vector<int>> :: iterator it ;
        for(auto a:vec){
            int fq = a[0] ;
            int ele = a[1] ;
            while(fq-->0){
                res.push_back(ele) ;
            }
        }
        return res ;
        
    }
};
