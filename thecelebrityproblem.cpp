
class Solution 
{
    // bool knows(vector<int>&M,int a,int b,int &n)
    // {
    //     if(M[a][b]==1){
    //         return true;
    //     }
    //     else
    //         return false;
    // }
    public: // TC->O(N)
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int> s;
        for(int i=0;i<n;i++)
        {
            s.push(i);
        }
        
        while(s.size()!=1)
        {
            int a=s.top();
            s.pop();
            int b=s.top();
            s.pop();
            
            if(M[a][b]==1){
                s.push(b);
            }
            else
            {
                s.push(a);
            }
        }
        int ans=s.top(); // single element left in stack which potential celebrity
        // abb row aur coloumn check karenge agar row me sare element 0 hai 
        // aur column me sare 1 hai exept diagonal element to bo celebrity hoga
        
        // row cheching of 1
        bool rowCheck=false;
        int rowcount=0;
        
        for(int i=0;i<n;i++)
        {
            if(M[ans][i]==0)
            rowcount++;
        }
        // all are zero's
        if(rowcount==n) // all elements are equal to 0
        {
            rowCheck=true;
        }
        
        
        // column cheching for 1
        
        bool colCheck=false;
        int colcount=0;
        
        for(int i=0;i<n;i++)
        {
            if(M[i][ans]==1)
            {
                colcount++;
            }
        }
        
        if(colcount==n-1){ // column me sare 1 hone chahiye diagonal ko chood ke isiliye use kiya hai n-1
            colCheck=true;
        }
        
        if(rowCheck==true&&colCheck==true)
        {
            return ans;
        }
        else
        {
            return -1;
        }
    }
    
};

