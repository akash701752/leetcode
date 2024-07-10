class Solution {
public:
    int minOperations(vector<string>& logs) {
        int sum=0;

        for(int i=0;i<logs.size();i++){

           
             if(logs[i]=="../"){
                if(sum<=0){
                    sum=0;
                }
                else{
                    sum--;
                }
            }
            else if(logs[i]=="./"){
                continue;
            }
            else{
                sum++;
            }
        }

        return sum;
    }
};
