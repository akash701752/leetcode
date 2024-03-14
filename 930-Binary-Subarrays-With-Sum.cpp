class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return (countAtLeastK(nums,goal)-countAtLeastK(nums,goal+1));
    }

    int countAtLeastK(vector<int>& A, int K){
        int size = A.size();
        int answer = 0;
        int windowSum = 0;
        for(int left=0, right=0; right<size; right++){
            windowSum += A[right];
            while(left<=right && windowSum >= K ){
                windowSum -= A[left];
                left++;
            }
            answer += left;
        }
        return answer;
    }

};
