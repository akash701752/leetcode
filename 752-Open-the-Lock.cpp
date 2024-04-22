class Solution {
public:
	int openLock(vector<string>& deadends, string target) {
		vector<int> visited(10001);
		string s="0000";
		queue<string> qu;
		qu.push(s);
		visited[0]=1;
		int step=0;
		for(auto& x:deadends)
		{
			if(x=="0000") return -1;
			int a=stoi(x);
			visited[a]=1;
		}
		while(!qu.empty())
		{
			int len=qu.size();
			while(len>0)
			{
				len--;
				string cur=qu.front();
				qu.pop();
				if(cur==target) return step;
				for(int i=0;i<4;i++)
				{
					char curC=cur[i];
					char nextC=curC=='9' ? '0':curC+1;
					char lastC=curC=='0' ? '9':curC-1;
					cur[i]=nextC;
					int temp=stoi(cur);


					//cout<<cur<<endl;
					if(!visited[temp])
					{
						qu.push(cur);
						visited[temp]=1;
					}
					cur[i]=lastC;
					temp=stoi(cur);
					if(!visited[temp])
					{
						qu.push(cur);
						visited[temp]=1;
					}
					cur[i]=curC;

				}
			}
			step++;

		}

		return -1;
	}
};
