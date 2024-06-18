#define vi vector<int>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
struct job{
    int d,p;
};

bool comp(job a,job b){
    return a.d<b.d;
}

class Solution {
public:
    int maxProfitAssignment(vi& d, vi& p, vi& w) {
        IOS;
        int i,j,n=d.size(),m=w.size();
        job a[n+1];
        for(i=0;i<n;i++){
            a[i].d=d[i];
            a[i].p=p[i];
        }
        
        a[n].d=INT_MAX;
        a[n].p=INT_MIN;
        
        sort(a,a+n,comp);
        int mxp[n];
        mxp[0]=a[0].p;
        
        for(i=1;i<n;i++)
            mxp[i]=max(a[i].p,mxp[i-1]);
        
        int ans=0;
        for(i=0;i<m;i++){
            if(a[0].d>w[i])
                continue;
            
            if(a[n-1].d<=w[i]){
                ans+=mxp[n-1];
                continue;
            }
            
            int l=0,h=n-1;
            while(l<=h){
                int m=l+(h-l)/2;
                if(a[m].d<=w[i])
                    l=m+1;
                else
                    h=m-1;
            }
            
            while(l && a[l].d>w[i])
                l--;
            
            ans+=mxp[l];
        }
        
        return ans;
        
        
    }
};
