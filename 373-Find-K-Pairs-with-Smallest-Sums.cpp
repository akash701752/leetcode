//class Solution {
//public:
    // typedef pair<int,pair<int,int>> p ;
    // vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    //     priority_queue<p,vector<p>,greater<p> > pq ;
    //     int sum = INT_MAX ;
    //     int i =0 , j= 0 , m = nums1.size() , n= nums2.size();
    //     for(i=0;i<m;i++)
    //     {
    //         int a = nums1[i] ;
    //         for(j=0;j<n;j++){
    //             int b = nums2[j] ;
    //             pq.push({a+b,{a,b}}) ;
    //         }
    //     }
    //     // sum = nums1[0] + nums2[0] ;
    //     // nums1[0]<nums2[0] ? i++ : j++ ; 
    //     // while(i<m && j<n)
    //     // {
    //     //     int s = nums1[i] + nums2[j] ;
    //     //     pq.push({s,{nums1[i],nums2[j]}}) ;
    //     //     if(nums1[i]<=nums2[j]){
    //     //         j++; 
    //     //     }
    //     //     else{
    //     //         i++ ;
    //     //     }
    //     // }
    //     vector<vector<int>> res ;
    //     while(k-->0 && pq.size()>0){
    //         pair<int,int> a = pq.top().second ;
    //         res.push_back({a.first,a.second}) ;
    //         pq.pop() ;
    //     }
    //     return res ;
    // }

     
//};

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) { // time complexity is O(m*nlogk), m = nums1 size, n = nums2 size
        priority_queue<pair<int,pair<int,int>>> pq;  // default: the greatest comes top
        for(int i=0;i<nums1.size();i++) {
            for(int j=0;j<nums2.size();j++) {
                int sum=nums1[i]+nums2[j];
                if (pq.size()<k) {
                    pq.push({sum,{nums1[i],nums2[j]}});
                }
                else if (sum<pq.top().first) {
                    pq.pop();
                    pq.push({sum,{nums1[i],nums2[j]}});
                } else {
                    break;  // save time! since we don't need to traverse the rest of vector 2
                }
            }
        }
        vector<vector<int>> ans;
        while(!pq.empty()) {
            ans.push_back({pq.top().second.first, pq.top().second.second});
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
