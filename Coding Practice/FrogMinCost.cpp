#include<bits/stdc++.h>
using namespace std;

int MinCost(int idx, int ht[])
{
    if(idx <= 0)
        return 0;
    if(idx == 1)
        return abs(ht[idx]-ht[idx-1]);
    return min(abs(ht[idx]-ht[idx-1]) + MinCost(idx-1, ht), abs(ht[idx]-ht[idx-2]) + MinCost(idx-2, ht));
}

int MinCostDP(int n, int ht[])
{
    vector<int> dp(n, 0);
    dp[1] = abs(ht[1] - ht[0]);
    for(int idx = 2; idx < n; ++idx)
        dp[idx] = min(abs(ht[idx]-ht[idx-1]) + dp[idx-1], abs(ht[idx]-ht[idx-2]) + dp[idx-2]);
    return dp[n-1];
}

int main(void)
{
    int n = 4;
    int ht[] = {10, 30, 40, 20};
    cout << MinCostDP(n-1, ht);
    return 0;
}