class Solution {
public:
    typedef pair<int,int> p ;
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int i , n = spells.size() , m = potions.size() ;
        sort(potions.begin(),potions.end()) ;
        vector<int> ans , pos ;
        for(i=0;i<n;i++){
            int count = m ;
            int low = 0 , high = m-1 , res = -1;
            while(low<=high){
                int mid = low+ (high-low)/2;
                if((long long)spells[i]*potions[mid]>=success){
                    res = mid ;
                    high = mid-1 ;
                }
                else {
                    low = mid +1;
                }
            }
            if(res==-1){
                ans.push_back(0) ;
            }
            else{
                ans.push_back(m-res) ;
            }
        }
        return ans ;
    }
};
