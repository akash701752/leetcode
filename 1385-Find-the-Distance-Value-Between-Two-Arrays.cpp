class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int ans = 0 , n1 = arr1.size() , n2 = arr2.size() , i , j  ;
        for(i=0;i<n1;i++){
            int count = 1 ;
            for(j=0;j<n2;j++){
                if(abs(arr1[i]-arr2[j])<=d){
                    count = 0 ;
                    break ;
                }
            }
            ans += count ;
        }
        return ans ;
    }
};
