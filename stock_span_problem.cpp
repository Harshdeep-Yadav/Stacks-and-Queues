class Solution
{
    public:



    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {

  // first approach {{}}
    


    //   vector<int> ans(n);
    //   ans[0]=1;
    //   stack<int> st;
    //   st.push(0);
  

    //   for(int i=1;i<n;i++){
    //          while(st.empty()==false&&price[st.top()]<=price[i])
    //       {
    //           st.pop();
    //       }
    //       if(st.empty())
    //       {
    //         ans[i]=i+1;  
    //       }
    //       else
    //       ans[i]=i-st.top();
    //       st.push(i);
    //   }
      
    //   return ans;
    
    
    
    // second approach {{best}}
    
    stack<pair<int,int>>st;
    vector<int> ans;
    for(int i=0;i<n;i++){
        if(st.size()==0)
        {
            ans.push_back(-1);
        }
        else if(st.size()>0&&st.top().first>price[i])
        {
            ans.push_back(st.top().second);
        }
        else if(st.size()>0&& st.top().first<=price[i])
        {
            while(st.size()>0&& st.top().first<=price[i])
            {
                st.pop();
            }
            if(st.size()==0)
            {
                ans.push_back(-1);
            }
            else
            {
                ans.push_back(st.top().second);
            }
        }
        st.push({price[i],i});
    }
        for(int i=0;i<ans.size();i++)
        {
            ans[i]=i-ans[i];
        }
        
        return ans;
    }
    
};