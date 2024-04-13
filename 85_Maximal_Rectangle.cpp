class Solution {
public:
    void NSL(vector<int>& heights,vector<int>&left,int n)
    {
        stack<pair<int,int>> st ;
        int i , p_ind = -1 ;
        for(i=0;i<n;i++)
        {
            if(st.size()==0)
            {
                left.push_back(p_ind) ;
            }
            else if(st.size()>0 && st.top().first < heights[i])
            {
                left.push_back(st.top().second) ;
            }
            else if(st.size()>0 && st.top().first >= heights[i])
            {
                while(st.size()>0 && st.top().first >= heights[i])
                {
                    st.pop() ;
                }
                if(st.size()==0)
                {
                    left.push_back(p_ind) ;
                }
                else
                {
                    left.push_back(st.top().second) ;
                }  
            }
            st.push(pair<int,int>(heights[i],i)) ;
        }
    }
    void NSR(vector<int>& heights,vector<int>&right,int n)
    {
        stack<pair<int,int>> st ;
        int i , p_ind = n ;
        for(i=n-1;i>=0;i--)
        {
            if(st.size()==0)
            {
                right.push_back(p_ind) ;
            }
            else if(st.size()>0 && st.top().first < heights[i])
            {
                right.push_back(st.top().second) ;
            }
            else if(st.size()>0 && st.top().first >= heights[i])
            {
                while(st.size()>0 && st.top().first >= heights[i])
                {
                    st.pop() ;
                }
                if(st.size()==0)
                {
                    right.push_back(p_ind) ;
                }
                else
                {
                    right.push_back(st.top().second) ;
                }  
            }
            st.push(pair<int,int>(heights[i],i)) ;
        }
        reverse(right.begin(),right.end());
    }    
    int MAH(vector<int>& heights, int n) 
    {
        vector <int> left  ;
        vector <int> right ;
        //int n = heights.size() ;
        NSL(heights,left,n) ;
        NSR(heights,right,n);
        
        vector <int> width(n);
        int i , area = INT_MIN  ;
        for(i=0;i<n;i++)
        {
            width[i] = right[i] - left[i] -1 ;
        }
        for(i=0;i<n;i++)
        {
            //cout<<"h = "<<heights[i] <<" width = "<<width[i] <<endl ;
            //cout<<heights[i]*width[i]<<endl ; ;
            area = max(area,heights[i]*width[i]) ;
        }
        return area ;
    }
    /*
    void NSL(vector<int>&heights,vector<int>&left,int n)
    {
        stack<pair<int,int>> st ;
        int i , p_ind = -1;
        for(i=0;i<n;i++)
        {
            if(st.size()==0){
                left.push_back(p_ind) ;
            }
            else if(st.size()>0 && st.top().first < heights[i]){
                left.push_back(st.top().second) ;
            }
            else if(st.size()>0 && st.top().first>=heights[i]){
                while(st.size()>0 && st.top().first>=heights[i]){
                    st.pop() ;
                }
                if(st.size()==0){
                    left.push_back(p_ind) ;
                }
                else{
                    left.push_back(st.top().second) ;
                }
            }
            //cout<<left[i] <<" ";
            st.push(pair<int,int>(heights[i],i)) ;
        }
        //cout<<endl ;
    }
    void NSR(vector<int>&heights,vector<int>&right,int n)
    {
        stack<pair<int,int>> st ;
        int i , p_ind = n;
        for(i=n-1;i>=0;i--)
        {
            if(st.size()==0){
                right.push_back(p_ind) ;
            }
            else if(st.size()>0 && st.top().first < heights[i]){
                right.push_back(st.top().second) ;
            }
            else if(st.size()>0 && st.top().first<=heights[i]){
                while(st.size()>0 && st.top().first<=heights[i]){
                    st.pop() ;
                }
                if(st.size()==0){
                    right.push_back(p_ind) ;
                }
                else{
                    right.push_back(st.top().second) ;
                }
            }
            //cout<<right[i] <<" ";
            st.push(pair<int,int>(heights[i],i)) ;
        }
        reverse(right.begin(),right.end()) ;
        //cout<<endl ;
    }
    int MAH(vector<int>&h,int n)
    {
        vector<int> left ;
        vector<int> right ;
        vector<int> width(n);
        NSL(h,left,n) ;
        NSR(h,right,n) ;
        int i , area = INT_MIN ;
        for(i=0;i<n;i++){
            width[i] = right[i]-left[i] -1 ;
            cout<<width[i]<<" ";
        }
        
        cout<<endl; 
        for(i=0;i<n;i++)
        {
            area = max(area,h[i]*width[i]) ;
        }
        cout<<area <<" "<<endl;
        return area ;
    }*/
    int maximalRectangle(vector<vector<char>>& matrix) 
    {
        vector <int> h ;
        int i , j , m , n ;
        m = matrix.size() ;
        n = matrix[0].size() ;
        //cout<<"m = " <<m << " n = "<<n <<endl ;
        if(m==1 && n==1){
            int c = matrix[0][0] ;
            if(c==48){
                return 0 ;
            }
            else{
                return 1 ; 
        }
        }
        for(i=0;i<n;i++){
            int c = matrix[0][i] ;
            if(c==48){
                h.push_back(0) ;
            }
            else{
                h.push_back(1) ;
            }
        }
        // for(i=0;i<n;i++){
        //     cout<<h[i]<<" ";
        // }
        //cout<<endl;
        int ar  ;
        ar = MAH(h,n) ;
        for(i=1;i<m;i++)
        {
            for(j=0;j<n;j++){
                if(matrix[i][j]==48){
                    h[j] = 0 ;
                }
                else if(matrix[i][j]==49){
                    int c = 1+ h[j] ;
                    h[j] = c ;
                }
                //cout<<h[j] << " ";
            }
            //cout<<endl ;
            ar = max(ar,MAH(h,n)) ;
        }
        return ar ;
    }
   
};
