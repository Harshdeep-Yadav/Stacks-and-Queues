

class Solution{
public:
    vector<int> leftSmaller(int n, int a[]){
       vector<int> ans;
       stack<int> st;
       for(int i=0;i<n;i++){
           if(st.size()==0)
           {
               ans.push_back(-1);
           }
           else if(st.size()>0,st.top()<a[i])
           {
               ans.push_back(st.top());
           }
           else if(st.size()>0&&st.top()>=a[i])
           {
               while(st.size()>0&&st.top()>=a[i]){
                   st.pop();
               }
               if(st.size()==0){
                   ans.push_back(-1);
               }
               else
                    ans.push_back(st.top());
           }
           st.push(a[i]);
       }
       return ans;
    }
};
