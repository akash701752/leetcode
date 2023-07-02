class Solution {
private:
    vector<int>seen;
    vector<vector<int>>mem;
    //index tells us which request we are currently on
    //config is a bitmask which encodes which requests have been selected 
    //so far
    int backtrack(vector<vector<int>>& requests,int config,int index){
        if(index==requests.size()){
            for(int i=0;i<seen.size();i++){
                if(seen[i]){
                    //it is not possible to fulfill these requests
                    return INT_MIN;
                }
            }
            return 0;
        } else if(mem[index][config]!=-1){
            return mem[index][config];
        } else {
            //we can ignore it the current request(at index)
            int ans1=backtrack(requests,config,index+1);
            seen[requests[index][0]]++;
            seen[requests[index][1]]--;
            //or we can choose to fulfill the current request
            int ans2=1+backtrack(requests,config^(1<<index),index+1);
            seen[requests[index][0]]--;
            seen[requests[index][1]]++;
            return mem[index][config]=max(ans1,ans2);
        }
    }
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        int r=requests.size();
        seen=vector<int>(n,0);
        mem=vector<vector<int>>(r,vector<int>(1<<r,-1));
        return backtrack(requests,0,0);
    }
};
