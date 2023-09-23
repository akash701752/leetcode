class Solution {
public:
    int longestStrChain(vector<string>& words) {
    int count=1; //calculate lingest chain
        map<string,int>coun;//number of predecessor of string 
        map<int,vector<string>>m1;//store string with there size
        int n=0,n1=INT_MAX;
        for(string a:words)
        {
            coun[a]=1;
            if(a.size()>n)//max size string
                n=a.size();
            if(n1>a.size())//shortest length strign 
                n1=a.size();
            m1[a.size()].push_back(a); 
       
           
        }
        for(int i=n1;i<n;i++)
        {
            
            vector<string>a,b;
             b=m1[i];
            a=m1[i+1];
            
            for(int k=0;k<b.size();k++)
            {
            for(int j=0;j<a.size();j++)
            {int c=0;
             
             int u=0;
                for(int h=0;h<a[j].size();h++)
                {
                    if(a[j][h]==b[k][u]){
                        u++;
                        c++;
                    }
                }
             if(c+1==i+1)
             {
                 int x=coun[b[k]]+1;
                 coun[a[j]]=max(coun[a[j]],x);
                 count=max(count,coun[a[j]]);
             }
            }
            }
        }
        
        return count;
    }
};
