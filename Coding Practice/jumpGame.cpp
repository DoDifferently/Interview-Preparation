class Solution {
public:
    int jump(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> dp(n, INT_MAX);
        dp[0] = 0;
        for(int i = 0; i < n; ++i)
        {
            for(int j = i+1; j < i+1+nums[i] and j < n; ++j)
            {
                dp[j] = min(dp[j], 1 + dp[i]);
                if(j == n-1)
                    return dp[j];
            }
        }
        return dp[n-1];
    }
    int jump2(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> dp(n, INT_MAX);
        dp[0] = 0;
        int currVal = 1, currMaxIdx = nums[0];
        int nextVal = 1, nextMaxIdx = 0;
        for(int i = 1; i < n; ++i)
        {
            if(i <= currMaxIdx)
                dp[i] = currVal;
            if(nextVal == currVal)
                nextMaxIdx = max(nextMaxIdx, i+nums[i]);
            if(i == currMaxIdx)
            {
                currVal++;
                currMaxIdx = nextMaxIdx;
                nextVal++;
            }
        }
        return dp[n-1];
    }
    int jump3(vector<int>& nums)
    {
        int n = nums.size();
        if(n <= 1)
            return 0;
        int jumps = 1, currMaxReach = nums[0];
        if(currMaxReach >= n-1)
            return jumps;
        int nextMaxReach = 0, i = 1;
        for(; i < n; ++i)
        {
            nextMaxReach = max(nextMaxReach, i+nums[i]);
            if(nextMaxReach >= n-1)
                break;
            if(i == currMaxReach)
            {
                jumps++;
                currMaxReach = nextMaxReach;
            }
        }
        return i == n-1 ? jumps : jumps+1;
    }
    int jump4(vector<int>& arr)
    {
        int n = arr.size();
        if(arr[0] == -1)
            return -1;
        if(n < 2)
            return 0;
        int maxReach = arr[0], steps = arr[0], jumps = 1;
        if(maxReach >= n-1)
            return jumps;
        for(int i = 1; i < n-1; ++i)
        {
            maxReach = max(maxReach, i+arr[i]);
            if(maxReach >= n-1)
                return i == n-1 ? jumps : jumps+1;
            steps--;
            if(steps == 0)
            {
                // If -ve value given, maxReach idx is before current idx
                if(i >= maxReach)
                    return -1;
                steps = maxReach - i;
                jumps++;
            }
        }
        return -1;
    }
};