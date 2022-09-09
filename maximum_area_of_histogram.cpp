class Solution
{
	public:
		int getMaxArea(vector<int> &arr, int n)
		{
			vector<int> left, right;
			stack<pair<int, int>> s1, s2;
			int pseudo_index = -1;
			int pseudo_index1 = n;
			for (int i = 0; i < n; i++)
			{
				if (s1.size() == 0)
				{
					left.push_back(pseudo_index);
				}
				else if (s1.size() > 0 && s1.top().first < arr[i])
				{
					left.push_back(s1.top().second);
				}
				else if (s1.size() > 0 && s1.top().first >= arr[i])
				{
					while (s1.size() > 0 && s1.top().first >= arr[i])
					{
						s1.pop();
					}

					if (s1.size() == 0)
					{
						left.push_back(pseudo_index);
					}
					else
					{
						left.push_back(s1.top().second);
					}
				}

				s1.push({ arr[i], i });
			}

			for (int i = n - 1; i >= 0; i--)
			{
				if (s2.size() == 0)
				{
					right.push_back(pseudo_index1);
				}
				else if (s2.size() > 0 && s2.top().first < arr[i])
				{
					right.push_back(s2.top().second);
				}
				else if (s2.size() > 0 && s2.top().first >= arr[i])
				{
					while (s2.size() > 0 && s2.top().first >= arr[i])
					{
						s2.pop();
					}

					if (s2.size() == 0)
					{
						right.push_back(pseudo_index1);
					}
					else
					{
						right.push_back(s2.top().second);
					}
				}

				s2.push({ arr[i], i });
			}

			reverse(right.begin(), right.end());
			int m = INT_MIN;
			for (int i = 0; i < n; i++)
			{
				int s = (right[i] - left[i] - 1) *arr[i];
				m = max(m, s);	// taking max after finding area
			}

			return m;
		}

	int largestRectangleArea(vector<int> &heights)
	{
		int n = heights.size();
		return getMaxArea(heights, n);

	}
};





// class Solution {
// public:
//     int getareaofhistogram(vector<int>& heights,int n){
//         stack<pair<int,int>> st;
//         stack<pair<int,int>>st2;
//         int pseudoind=-1;
//         vector<int>nsr,nsl;
//         vector<int>width;
//         vector<int>area;
//         // int n=heights.size();
//         for(int i=0;i<n;i++)
//         {
//            if(st.empty()){
//                nsl.push_back(pseudoind);   
//            }
//             else if(st.size()>0&&st.top().first<heights[i]){
//                 nsl.push_back(st.top().second);
//             } 
//             else if(st.size()>0&&st.top().first>=heights[i]){
//                 while(st.size()>0&&st.top().first>=heights[i]){
//                     st.pop();
//                 }
//                 if(st.size()==0){
//                     nsl.push_back(pseudoind);
//                 }
//                 else
//                     nsl.push_back(st.top().second);
//             }
//             st.push({heights[i],i});
//         }

    
//         for(int i=n-1;i>0;i--)
//         {
//             if(st2.empty()){
//                nsr.push_back(n);   
//            }
//             else if(st2.size()>0&&st2.top().first<heights[i]){
//                 nsr.push_back(st2.top().second);
//             } 
//             else if(st2.size()>0&&st2.top().first>=heights[i]){
//                 while(st2.size()>0&&st2.top().first>=heights[i]){
//                     st2.pop();
//                 }
//                 if(st2.size()==0){
//                     nsr.push_back(n);
//                 }
//                 else
//                     nsr.push_back(st2.top().second);
//             }
//             st.push({heights[i],i});
//         }
//     reverse(nsr.begin(),nsr.end());

//     int m=INT_MIN;
//     for(int i=0;i<n;i++){
//         long  s=(nsr[i]-nsl[i]-1)*heights[i];
//         m=max(m,s);
//     }
//     return m;
//     }

//     int largestRectangleArea(vector<int>heights)
//     {
//         int n=heights.size();
//             return getareaofhistogram(heights,n);
//     }
// };