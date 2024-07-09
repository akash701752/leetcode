class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n=customers.size();
        double sum=0;
        int start=customers[0][0];
        int finish=customers[0][1]+start;
        int totaltime=finish-start;
         sum=sum+totaltime;
        for(int i=1;i<n;i++){
            if(finish<=customers[i][0]){
             start=customers[i][0];
             finish=customers[i][1]+start;
             totaltime=finish-start;
            sum=sum+totaltime;
            }
            else{
                start=finish;
                finish=customers[i][1]+start;
                totaltime=finish-customers[i][0];
                sum=sum+totaltime;
            }
        }
        double average=sum/n;
        return average;
    }
};
