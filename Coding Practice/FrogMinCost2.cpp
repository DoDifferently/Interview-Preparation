#include<bits/stdc++.h>
using namespace std;

long long minimumCost(vector<int> stones, int k)
{
    int n = stones.size();
    vector<int> dp(n+1, INT_MAX);
    dp[0] = 0;
    for(int i = 1; i < n; ++i)
    {
        for(int j = i-1; j >= 0 and (i-j) <= k; j--)
        {
            dp[i] = min(dp[i], dp[j] + abs(stones[i]-stones[j]));
        }
    }
    return dp[n-1];
}