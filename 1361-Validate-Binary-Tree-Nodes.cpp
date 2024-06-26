class Solution {
public:
    vector<int>parent;
    int find(int x)
    {
        if(x==parent[x])
        {
            return x;
        }
        return parent[x]=find(parent[x]);
    }
    bool validateBinaryTreeNodes(int n, vector<int>& l, vector<int>& r)
    {
        int count=n;
        parent.resize(n+1);
        for(int i=0;i<n+1;i++)
        {
           parent[i]=i;
        }
        vector<int>v(n+1,0);
        for(int i=0;i<n;i++)
        {
            if(l[i]!=-1)
            {
                v[l[i]]++;
                if(v[l[i]]>1)
                {
                    return false;
                }
                int x=find(i);
                int y=find(l[i]);
                if(x!=y)
                {
                    count--;
                    parent[x]=y;
                }
                else
                {
                    return false;
                }
            }
            if(r[i]!=-1)
            {
                v[r[i]]++;
                if(v[r[i]]>1)
                {
                    return false;
                }
                int x=find(i);
                int y=find(r[i]);
                if(x!=y)
                {
                    count--;
                    parent[x]=y;
                }
                else
                {
                    false;
                }
            }
        }
        return count==1;
    }
};
