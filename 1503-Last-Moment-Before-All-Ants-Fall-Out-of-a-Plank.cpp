class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        if(left.size()==0){
            return n - *min_element(right.begin(),right.end());
        }
        if(right.size()==0){
            return *max_element(left.begin(),left.end());
        }
        int left_num = *max_element(left.begin(),left.end());
        int right_num = n-*min_element(right.begin(),right.end());
        
        return max(left_num,right_num);
    }
};
