class MyStack {
public:
    queue<int> q1 ,q2;
    MyStack() {
        
    }
    
    void push(int x) {
        q2.push(x) ;
        while(q1.size()>0){
            q2.push(q1.front()) ;
            q1.pop() ;
        }
        queue<int>q = q1;
        q1 = q2 ;
        q2 = q ;
    }
    
    int pop() {
        if(q1.size()<0){
            return -1;
        }
        int ans = q1.front() ;
        q1.pop() ;
        return ans ;
    }
    
    int top() {
        return q1.front() ;
    }
    
    bool empty() {
        if(q1.empty()){
            return true ;
        }
        return false ;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
