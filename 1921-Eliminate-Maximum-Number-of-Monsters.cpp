class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<int> time(n,0);
        for(int i = 0; i < n; i++)
            time[i] = ceil((double)dist[i]/speed[i]);
			
        sort(time.begin(),time.end());
        int curr = 0;
        for(int i = 0; i < n; i++){
            if(time[i]<=curr)
                break;
            curr++;
        }
        return curr;
    }
};
