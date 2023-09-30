class Solution {
public:
    bool find132pattern(vector<int>& a) {
        // bool ans = false ;
        // int n = nums.size() ;
        // int i = 0 , j = 1 , k =2;
        // if(n<3){
        //     return false;
        // }
        // while(k<n){
        //     if(nums[i]<nums[j] && nums[j]>nums[k] && nums[i]<nums[k]){
        //         ans = true;
        //         break;
        //     }
        //     i++;
        //     j++;
        //     k++;
        // }
        // return ans;

        int n=a.size();
        stack<int> s;
        vector<int> m(n);
        m[0]=a[0];
        for(int i=1;i<n;i++){
            m[i]=min(m[i-1],a[i]);
        }
        for(int i=n-1;i>=0;i--){
            if(a[i]>m[i]){
                while(s.size()&&s.top()<=m[i])s.pop();
                if(s.size()&&s.top()<a[i])return 1;
                s.push(a[i]);
            }
        }
        return 0;
    }
};
