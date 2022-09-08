class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        vector<int> v;
        int n =asteroids.size();
        for(int i=0;i<n;i++)
        {
            //all element greater than 0 form given array simply push into stack
            if(asteroids[i]>0)
                st.push(asteroids[i]);
            else{
                // when find smaller than the arrays value
                while(st.size()>0&&st.top()>0&&st.top()<-asteroids[i]){
                    st.pop();
                }
                // when finds equal to st.top() and curr element value pop st top (destroyed as given in the question)
                if(st.size()>0&&st.top()==-asteroids[i])
                {
                    st.pop();
                }
                // when top of stack has greater value than current element do nothing 
                else if(st.size()>0&&st.top()>-asteroids[i]){
                    
                }
                 else
                 {
                     st.push(asteroids[i]);
                 }
            }
        }
        while(!st.empty())
        {
            v.push_back(st.top());
            st.pop();
        }
        reverse(v.begin(),v.end());
        return v;
    }
};