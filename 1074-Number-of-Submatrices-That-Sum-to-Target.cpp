class Solution {
public:
	int helper(vector<int>& temp,int target){
		int n=temp.size();
		unordered_map<int,int> m;
		m[0]=1;
		int ans=0;
		int prefixSum=0;
		for(int i=0;i<n;i++){
			prefixSum+=temp[i];
			if(m.count(prefixSum-target)){
				ans+=m[prefixSum-target];
			}
			m[prefixSum]+=1;
		}
		return ans;
	}
	int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
		int res=0;
		int m=matrix.size();
		int n=matrix[0].size();
		for(int i=0;i<m;i++){
			vector<int> temp(n,0);
			for(int j=i;j<m;j++){
				for(int k=0;k<n;k++){
					temp[k]+=matrix[j][k];
				}
				 res+=helper(temp,target);
			}    
		}

		return res;

	}
};
