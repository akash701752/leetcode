class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
       vector<int> count(100, 0);
        for (int i = lowLimit; i <= highLimit; i++) {
            int num = i;
            int sum = 0;
            while (num) {
                sum += num%10;
                num /= 10;
            }
            count[sum]++;
        }
        sort(count.begin(), count.end());
        return count[count.size()-1]; 
    }
};
