class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev = 0, curr;
		int ans = 0;
		for(int i = 0; i < bank.size(); i++){
			curr = 0;
			for(int j = 0; j < bank[0].size(); j++){
				curr += (bank[i][j] - '0');
			}
			if(curr > 0){
				ans += prev * curr;
				prev = curr;
			}
		}  
		return ans;
    }
};
