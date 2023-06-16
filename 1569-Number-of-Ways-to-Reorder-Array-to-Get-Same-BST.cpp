class Solution {
public:
    const int Mod = 1e9 + 7;

    int memo[1001][1001];
    int nCr(int n, int r){
        assert(n >= r);
        if (r == 0 || n == r) 
            return 1;
        else if (r == 1 ) 
            return n;
        else if (memo[n][r] != 0) { 
            return memo[n][r];
        }
        else 
            return memo[n][r] = (nCr(n-1, r) + nCr(n-1, r-1))%Mod;
    }
    int numOfWaysHelper(vector<int>& a) {
        if (a.empty()) {
            return 1; // base case
        }
        vector<int> greater, smaller; 
        int n = (int)a.size(); 
        for(int i=1;i<n;i++){
            if(a[i] > a[0]) {
                greater.push_back(a[i]);
            } else { 
                smaller.push_back(a[i]);
            }
        }
        int gcnt = (int)greater.size();
        int scnt = (int)smaller.size(); 
        return ((nCr(gcnt + scnt, gcnt) * 1LL * numOfWaysHelper(greater))%Mod * 1LL * numOfWaysHelper(smaller))%Mod ;
    }

    int numOfWays(vector<int> &nums){
        return ((numOfWaysHelper(nums) - 1)%Mod + Mod)%Mod;
    };
    
};
