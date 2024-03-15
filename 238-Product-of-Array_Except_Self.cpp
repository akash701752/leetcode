class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector <int> res ;
        int i , sum=1 , j ;
        /*
        for(i=0;i<nums.size();i++)
        {
            sum = 1 ;
            for(j=0;j<nums.size();j++)
            {
                if(i!=j)
                {
                    sum = sum*nums[j] ;
                }
            }
            res.push_back(sum) ;
        }
        return res ;
        */
        /*
        int n= nums.size() ;
        for(i=0;i<n;i++)
        {
            sum= nums[i]*sum ;
        }
        for(i=0;i<n;i++)
        {
            res.push_back(sum/nums[i]) ;
        }
        return res ;
        */
        int n= nums.size() ;
        vector<int> ans(n,1) ;
        int p = 1 ;
        for(i=0;i<n;i++)
        {
            ans[i] = p ;
            p = p*nums[i] ;
        }
        p = 1;
        for(i=n-1;i>=0;i--)
        {
            ans[i] = ans[i]*p ;
            p = p*nums[i] ;
        }
        return ans ;
    }
    
};
