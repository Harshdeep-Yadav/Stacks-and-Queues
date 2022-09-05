
int top=-1;
//Function to push an integer into the stack.
void MyStack :: push(int x)
{
   arr[++top]=x;
}

//Function to remove an item from top of the stack.
int MyStack :: pop()
{
    if(top==-1) return -1;
       int ele=arr[top];
       top--;
       return ele;
}