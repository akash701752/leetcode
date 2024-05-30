class Solution {
public:
    int countTriplets(vector<int>& arr) {
       int n=arr.size(),c=0;
        vector<int> xr(n);
        xr[0]=arr[0];
        for(int i=1;i<n;i++)
            xr[i]=xr[i-1]^arr[i];
        for(int i=0;i<n;i++)
        {    int p=xr[i];
            for(int j=i+1;j<n;j++)
            {
                for(int k=j;k<n;k++)
                {
                    if((xr[j-1]^xr[i]^arr[i])==(xr[k]^xr[j]^arr[j])) c++;
                }
            }
        }
        return c; 
    }
};
