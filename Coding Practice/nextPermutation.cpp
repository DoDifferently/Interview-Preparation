#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
        void nextPermutation(vector<int>& nums)
        {
            int i = nums.size()-2;
            while(i >= 0 and nums[i] >= nums[i+1])
                i--;
            if(i >= 0)
            {
                int j = i+1;
                while(j < nums.size() and nums[j] > nums[i])
                    j++;
                swap(nums[i], nums[j-1]);
            }
            reverse(nums.begin()+i+1, nums.end());
        }
};

