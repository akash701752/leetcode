class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n=rating.size();

        int count=0;

        for(int i=1;i<n-1;i++){
            int leftsmaller=0,rightsmaller=0,leftgreater=0,rightgreater=0;

            for(int j=0;j<i;j++){
                if(rating[j]<rating[i]){
                    leftsmaller++;
                }
                else if(rating[j]>rating[i]){
                    leftgreater++;
                }
            }

            for(int j=i+1;j<n;j++){
                if(rating[j]<rating[i]){
                    rightsmaller++;
                }
                else if(rating[j]>rating[i]){
                    rightgreater++;
                }
            }

            count+=leftsmaller*rightgreater+leftgreater*rightsmaller;
        }

        return count;

    }
};
