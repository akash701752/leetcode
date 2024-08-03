class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        vector<int>helper(1001,0);
        for(int i:target){
            helper[i]++;
        }
        for(int j:arr){ 
            helper[j]--;
        }
        for(int i:helper){ 
            if(i!=0){
                return false;
            }
        }
        return true;
    }
};
