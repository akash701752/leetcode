class Solution {
public:
    bool check(vector <int> &a , int mid,int p){
        int n=a.size();
        int cnt=0;
        for(int i=1;i<n;i++){
            if(a[i]-a[i-1]<=mid){
                cnt++;
                i++;
            }
            if(cnt==p) return 1;
        }
        return 0;
    }
    int minimizeMax(vector<int>& a, int p) {
        int n=a.size();
        if(p==0 || n==1) return 0;
        sort(a.begin(),a.end());
        int s=0,e=a[n-1]-a[0],mid=s+(e-s)/2;
        bool ans;
        while(e-s>1){
            ans=check(a,mid,p);
            if(ans){
                e=mid;
            }
            else{
                s=mid+1;
            }
            mid=s+(e-s)/2;
        }
        if(check(a,s,p)){
            return s;
        }
        return e;
    }
};
