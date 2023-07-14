class Solution {
public:
	int longestSubsequence(vector<int>& arr, int difference) {
		if(arr.size()==0) return 0;
		unordered_map<int,int> m;
		int ans=1;
		for(int i=0;i<arr.size();i++){
			if(m.count(arr[i]-difference)){
				m[arr[i]]=m[arr[i]-difference]+1;
				ans=max(ans,m[arr[i]]);
			}
			else{
				m[arr[i]]=1;
			}
		}     
		return ans; 
	}
};
