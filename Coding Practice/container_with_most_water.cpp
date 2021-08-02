#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
        int maxArea(vector<int>& height)
        {
            int res = 0, left = 0, right = height.size()-1;
            // While the water can be stored between buildings
            while(left < right)
            {
                if(height[left] < height[right])
                {
                    res = max(res, (right-left)*height[left]);
                    left++;
                }
                else if(height[right] < height[left])
                {
                    res = max(res, (right-left)*height[right]);
                    right--;
                }
                else
                {
                    res = max(res, (right-left)*height[left]);
                    left++;
                    right--;
                }
            }
            return res;
        }
};