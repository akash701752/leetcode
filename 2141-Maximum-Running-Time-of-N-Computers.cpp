class Solution {
public:
    
    #define ll long long
    
	// checking if possible to assign 'mins' to each computer
    bool possible(int n, vector<int> &bat, ll int mins){
        ll int s=0;
        for(int i=0;i<bat.size();i++){
            s += bat[i];
            if(s>=mins){
                s-=mins;
                n--;
            }
            if(n==0) return true;
        }
        return false;
    }
    
    long long maxRunTime(int n, vector<int> &bat) {
        ll int l=1, r=0;
        
        for(int i=0;i<bat.size();i++) r += bat[i];
        r/=n; // max. minutes will be possible when all computers are assigned average of total battery minutes
        
        sort(bat.begin(),bat.end());
        while(l<r){
            ll int m=l+(r-l+1)/2;
            
            if(possible(n,bat,m)){
                l=m;
            }else{
                r=m-1;
            }
        }
        return l;
    }
};
