class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        
         long long res = 0;
        
        long long ans = 0;
        
        vector<long long> suff;
        
        vector<long long> pref;
        
        if(k == 1 || k == weights.size()) {
            
            return 0;
        }
        
        k = k-1;
    
        for(long long i=0;i < weights.size() -1;i++){
            pref.push_back(weights[i] + weights[i+1]);
            
        }
        
        sort(pref.begin(),pref.end(),greater<long long int >());

        for(long long i=0;i < weights.size() - 1;i++){
            suff.push_back(weights[i] + weights[i+1]);
        }
        
        sort(suff.begin(),suff.end());
        
        for(long long j = 0; j < k;j++){
            
            res = res + pref[j];
        }
        
        for(long long l = 0;l < k;l++){
            ans += suff[l];
        }
        
        return res - ans;
    }
};
