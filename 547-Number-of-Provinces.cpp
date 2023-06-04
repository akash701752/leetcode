class Unionfindset{
	private:
	vector<int> parent;
	vector<int> rank;
	public:
	Unionfindset(int n){
		rank=vector<int>(n,0);
		parent=vector<int>(n,0);
		for(int i=0;i<n;i++){
			parent[i]=i;
			rank[i]=0;
		}
	}

	bool union_(int x,int y){
		int x_root=find_(x);
		int y_root=find_(y);
		if(x_root==y_root){
			return false;
		}
		if(rank[x]>rank[y]){
			parent[y_root]=x_root;
		}
		else if(rank[y]>rank[x]){
			parent[x_root]=y_root;
		}
		else if(rank[y]==rank[x]){
			parent[x_root]=y_root;
			rank[y_root]++;
		}
		return true;
	}

	int find_(int x){
		if(x!=parent[x]){
			parent[x]=find_(parent[x]);
		}
		return parent[x];
	}
};

class Solution {
public:
	int findCircleNum(vector<vector<int>>& M) {
		int n=M.size();
		Unionfindset S(n);
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				if(M[i][j]==1){
					S.union_(i,j);
				}
			}
		}
		set<int> myset;
		for(int i=0;i<n;i++){
			myset.insert(S.find_(i));
		}
		int res=0;
		for(auto i:myset){
			res++;
		}
		return res;
	}
};
