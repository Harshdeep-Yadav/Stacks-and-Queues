class MyQueue {
        stack<int>s1;
        stack<int>s2; 
public:
    MyQueue() {
       
    }
    
    void push(int x) {
        while(!s1.empty()){
            int val=s1.top();
            s1.pop();
            s2.push(val);
        }
        
        s2.push(x);
        
        while(!s2.empty()){
            int val1=s2.top();
            s2.pop();
            s1.push(val1);
        }
    }
    
    int pop() {
        int ans=s1.top();
        s1.pop();
       return ans;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        if(s1.empty()){
            return true;
        }
        else
            return false;
    }
};


 while(!input.empty()){
            output.push(input.top());
            input.pop();
        }
        output.push(x);
        while(!output.empty()){
            input.push(output.top());
            output.pop();
        }