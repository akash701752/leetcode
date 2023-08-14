class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        int n = nums.size() , i ;
        priority_queue <int , vector<int> , greater<int> > minh ;
        for(i=0;i<n;i++)
        {
            minh.push(nums[i]) ;
            if(minh.size()>k)
            {
                minh.pop() ;
            }
        }
        return minh.top() ;
    }
};
