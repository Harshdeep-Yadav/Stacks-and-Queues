//Function to push an element into stack using two queues.
void QueueStack :: push(int x)
{   
    q2.push(x);
    while(!q1.empty()){
        q2.push(q1.front());
        q1.pop();
    }
    swap(q1,q2);
}

//Function to pop an element from stack using two queues. 
int QueueStack :: pop()
{    if(q1.empty())return -1;
       int res=q1.front();
       q1.pop();
       return res;
}
