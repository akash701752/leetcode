class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size() ;
        bool flag = false ;
        int mx = 0 , len = 0 , i = 0 ;
        while(i<n-1){
            if(arr[i]>arr[i+1]){
                flag = true ;
                int count = 1 ;
                while(i<n-1 && arr[i]>arr[i+1]){
                    count++;
                    i++;
                }
                if(len!=0 && count!=0){
                    mx = max(mx,len+count);
                }
                len = 0;
            }
            else if(arr[i]<arr[i+1]){
                len++;
                i++;
            }
            else{
                len = 0 ;
                i++;
            }
        }
        if(flag){
            return mx ;
        }
        return 0;
    }
};
