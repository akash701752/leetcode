class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        sort(A.begin(),A.end());
        int k;
        int cnt=0;
        for(int i=1;i<A.size();i++)
        {
            if(A[i]<=A[i-1])
                {k=A[i-1]-A[i]+1;
            cnt+=k;
            A[i]+=k;}
        }
        return cnt;
    }
};
