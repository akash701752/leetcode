class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());

        int l=0, r=position.back()-position.front();
        while(l<=r){
            int mid=l+(r-l)/2;
            if(canSpaceBalls(position, m, mid)){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return r;
    }

    bool canSpaceBalls(vector<int>& pos, int balls, int space){

        for(int i=0, lastpos=pos[0]-INT_MAX; i<pos.size() && balls; i++){
            if(pos[i]-lastpos < space){
                continue;
            }
            balls--;
            lastpos=pos[i];
        }
        return balls==0;
    }
};
