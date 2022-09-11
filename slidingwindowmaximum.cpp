// class Solution {
// public:  // NAIVE APPROACH OF TC=O(N2)

//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//        int n=nums.size();
//         vector<int> ans;
//         for(int i=0;i<n-k;i++)
//         {
//             int maxi=nums[i];
//             for(int j=i;j<i+k-1;i++)
//             {
//                 maxi=max(nums[j],maxi);
//             }
//             ans.push_back(maxi);
//         }
//         return ans;
//     }
// };


// OPTIMAL SOLUTION OF TC:-O(N)

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(!dq.empty()&&dq.front()==i-k)
            {
                dq.pop_front();
            }
            // if current value is greater than the prev value;
            while(!dq.empty()&&nums[i]>=nums[dq.back()])// dq.back( ->storing index for prev element in the array)
            {
                dq.pop_back();
            }
            dq.push_back(i);
            
            if (i - k + 1 >= 0) // pushing max element to ans
            ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};