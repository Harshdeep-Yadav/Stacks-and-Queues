class Solution {
public:
    int trap(vector<int>& height) {
        int sum=0;
        int n=height.size();
        int water[n];
        int maxl[n];
        int maxr[n];
        
        maxl[0]=height[0];
        for(int i=1;i<n;i++)
        {
            maxl[i]=max(maxl[i-1],height[i]);
        }
        
        maxr[n-1]=height[n-1];
        
        for(int i=n-2;i>=0;i--)
        {
            maxr[i]=max(maxr[i+1],height[i]);
        }
        
        for(int i=0;i<n;i++)
        {
            water[i]=min(maxl[i],maxr[i])-height[i];
        }
        
        for(int i=0;i<n;i++)
        {
            sum=sum+water[i];
        }
        
        return sum;
    }
};


//````````````````````````````````````````````````//```````````````````````````````````//````````````````````````


class Solution
{
public:

int trap(vector<int> &height)
{
    int n = height.size();
    int left = 0, right = n - 1;
    int res = 0;
    int maxLeft = 0, maxRight = 0;
    while (left <= right)
    {
        if (height[left] <= height[right])
        {
            if (height[left] >= maxLeft)
            {
                maxLeft = height[left];
            }
            else
            {
                res += maxLeft - height[left];
            }
            left++;
        }
        else
        {
            if (height[right] >= maxRight)
            {
                maxRight = height[right];
            }
            else
            {
                res += maxRight - height[right];
            }
            right--;
        }
    }
    return res;
}
};