class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n=arr.size(),count=1;
        int max_val=max(arr[0],arr[1]);
        for(int i=2 ; i<n ; i++)
        {
            if(count==k) return max_val;
            if(arr[i]>max_val)
            {
                max_val = arr[i];
                count = 1;
            }
            else count++;
        }
        return *max_element(arr.begin(),arr.end());
    }
};
