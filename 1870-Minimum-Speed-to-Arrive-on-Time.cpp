class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();
        if(n-1 >= hour) return -1;
        int l = 1, r = INT_MAX;
        while(l < r){
            int m = l + (r-l)/2;
  
            double h = Hour(dist,m);
            if(h == hour)  return m;
            if(h < hour){
                r = m;
            }
            else{
                l = m+1;
            }
        }
        return l;
    }
    
    double Hour(vector<int>& dist, int speed){
        int n = dist.size();
        int h = 0;
        for(int i = 0 ; i < n-1; ++i) h += (dist[i]+speed-1)/speed;
        return (double)h +(double)dist[n-1] / speed ;
    }
};
