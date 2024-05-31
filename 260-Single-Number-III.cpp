class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorVal = 0;
        for(auto num : nums) xorVal ^= num;

        int firstBitEquals1=0;
        for(int i=0; i <= 31; i++) {
            int curBit = ( xorVal & ( 1 << i ) ) >> i;
            if(curBit) {
                firstBitEquals1 = i; break;
            }
        }

        int first = 0, second = 0;
        for(auto num : nums) {
            int curkthBit = ( num & ( 1 << firstBitEquals1 ) ) >> firstBitEquals1;
            if(curkthBit){
                first ^= num;
            }
            else{
                second ^= num;
            }
        }

        vector<int> res = {first, second};
        return res;
    }
};
