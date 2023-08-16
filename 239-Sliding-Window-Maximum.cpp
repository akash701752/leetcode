class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        int i = 0, j = 0 , n = nums.size() ;
        list <int> l ;
        vector <int> res ;
        while(j<n)
        {
            while(l.size()>0 && l.back()<nums[j])
            {
                l.pop_back() ;
            }
            l.push_back(nums[j]);
            if((j-i+1)<k)
            {
                j++;
            }
            else if((j-i+1)==k)
            {
                res.push_back(l.front()) ;
                if(nums[i]==l.front())
                {
                    l.pop_front() ;
                }
                i++ ;
                j++ ;
            }
        }
        return res ;
    }
};

// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         //Pair<int,int> contains (nums[i],index)
//         deque<pair<int,int>> dq;  //We will store elements in the deque only inside our current window
//         vector<int> ans;
        
//         for(int i=0;i<nums.size();++i)
//         {
//             if(!dq.empty() and dq.front().second<=(i-k))    //Remove front element if it goes out of window size
//                 dq.pop_front();
//             while(!dq.empty() and dq.back().first<nums[i])  //Maintain elements in DSC order
//                 dq.pop_back();
//             dq.push_back(make_pair(nums[i],i));     //Push current NODE
//             if(i>=(k-1))
//                 ans.push_back(dq.front().first);    //Include maximum of cuurrent window
//         }
//         return ans;
//     }
// };
